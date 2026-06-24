SRC_FILES = driver.cc src/vm.cc
CC_FLAGS = -Wall -Wextra -std=c++20 -fsanitize=address,undefined -Iincludes/

.PHONY: all clean

all:
	mkdir -p bin/
	clang++ ${CC_FLAGS} ${SRC_FILES} -o ./bin/driver

clean:
	rm -rf bin/