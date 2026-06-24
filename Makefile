# Toolchain
CXX     := clang++
AS      := riscv64-linux-gnu-as
LD      := riscv64-linux-gnu-ld
QEMU    := qemu-riscv64

# Flags
CXXFLAGS := -Wall -Wextra -std=c++20 -fsanitize=address,undefined -Iinclude/
ASFLAGS  := -march=rv64gc
LDFLAGS  := -static

# Compiler backend: src/*.cc -> build/compiler
COMPILER_SRCS := $(wildcard src/*.cc)
COMPILER_BIN  := build/compiler

# Supplied at the command line, e.g. `make run SRCS="strlen.s driver.s"`
SRCS    ?=
BIN     ?= a.out
OBJS    := $(SRCS:.s=.o)

.PHONY: compiler run test clean

compiler: $(COMPILER_BIN)

$(COMPILER_BIN): $(COMPILER_SRCS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(BIN)
	@$(QEMU) ./$(BIN) ; echo "exit code: $$?"

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# Runs every tests/cases/*.ll through the compiler, assembles + links the
# result, and runs it under qemu. Checks the exit code against
# tests/expected/<name>.exit if present, and diffs the generated assembly
# against tests/expected/<name>.s if present.
test: compiler
	@mkdir -p build/tests
	@fail=0; \
	for ll in tests/cases/*.ll; do \
		[ -e "$$ll" ] || continue; \
		name=$$(basename "$$ll" .ll); \
		asm=build/tests/$$name.s; \
		obj=build/tests/$$name.o; \
		bin=build/tests/$$name; \
		$(COMPILER_BIN) "$$ll" -o "$$asm" || { echo "FAIL $$name: compile"; fail=1; continue; }; \
		if [ -f "tests/expected/$$name.s" ] && ! diff -u "tests/expected/$$name.s" "$$asm"; then \
			echo "FAIL $$name: generated asm differs from tests/expected/$$name.s"; fail=1; continue; \
		fi; \
		$(AS) $(ASFLAGS) "$$asm" -o "$$obj" && $(LD) $(LDFLAGS) "$$obj" -o "$$bin" \
			|| { echo "FAIL $$name: assemble/link"; fail=1; continue; }; \
		$(QEMU) "$$bin" > /dev/null 2>&1; actual=$$?; \
		if [ -f "tests/expected/$$name.exit" ]; then \
			expected=$$(cat "tests/expected/$$name.exit"); \
			if [ "$$actual" != "$$expected" ]; then \
				echo "FAIL $$name: exit $$actual, expected $$expected"; fail=1; continue; \
			fi; \
		fi; \
		echo "PASS $$name (exit $$actual)"; \
	done; \
	exit $$fail

clean:
	rm -rf build $(OBJS) $(BIN)