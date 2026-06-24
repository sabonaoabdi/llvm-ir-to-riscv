goal:

manually parse llvm ir and convert it into risc-v assembly code
- subset:
add, sub, addi, li,     // arithmetic and constants
lw, sw, (or ld, sd)     // memory(i32); add ld/sd when working with i64
beq, bne, blt, bge,     // compare-and-branch
jal, jalr, j,           // unconditional jump, call, return


main parts:
-parsing into some type of AST
    -don't even know yet
-register allocation
    -write the graph functions
    -write the node functions
-composing the output assembly file
    -write instruction encoding