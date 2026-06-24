#include "../includes/vm.hpp"

static const std::vector<uint32_t> program {
    VM::InstructionSet::PSH, 5,
    VM::InstructionSet::PSH, 5,
    VM::InstructionSet::ADD,
    VM::InstructionSet::LOAD, VM::Registers::x31,
    VM::InstructionSet::HLT,
};


int main(int argc, char* argv[]) {
    VM my_vm(program);
    my_vm.run();
    my_vm.register_dump();
    return 0;
}