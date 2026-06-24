right now it implements a very simple stack-based vm

could make a VM superclass and implement specific architecture classes that can be instantiated in driver to emulate games or other things

TODO: handle malformed programs
- ADD/POP/LOAD pop from the stack without checking if it's empty (stack underflow is currently UB)
- execution assumes the program ends in HLT; if ip_ runs past the end, fetch_instr() throws std::out_of_range uncaught