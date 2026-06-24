#include "includes/vm.hpp"

static const std::vector<int> program {
    VM::InstructionSet::PSH, 5,
    VM::InstructionSet::PSH, 5,
    VM::InstructionSet::MUL,
    VM::InstructionSet::LOAD, VM::Registers::A,
    VM::InstructionSet::HLT,
};


int main(int argc, char* argv[]) {
    VM my_vm(program);
    my_vm.run();
    my_vm.register_dump();
    return 0;
}