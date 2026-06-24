#include "../includes/vm.hpp"
#include <iostream>

VM::VM(std::vector<uint32_t> program) : program_(std::move(program)) {}

void VM::run() {
    while (running_) {
        eval_instr(decode_instr());
        ip_++;
    }
}

void VM::register_dump() const {
    for (unsigned int i = 0; i < registers_.size(); ++i) {
        std::cout << "Register x" 
        << i 
        << ": " << registers_.at(i) << std::endl;
    } 
}

int VM::get_register(Registers r) const {
    return registers_.at(r);
}

int VM::decode_instr() const {
    return program_.at(ip_);
}

bool VM::stack_has(std::size_t n) {
    if (stack_.size() < n) {
        std::cerr << "Error: Stack underflow" << std::endl;
        running_ = false;
        return false;
    }
    return true;
}

void VM::eval_instr(int instr) {
    switch (instr) {
        case InstructionSet::HLT: {
            running_ = false;
            break;
        }
        case InstructionSet::PSH: {
            stack_.push(program_.at(++ip_));
            break;
        }
        case InstructionSet::ADD: {
            if (!stack_has(2)) break;
            int a = stack_.top();
            stack_.pop();
            int b = stack_.top();
            stack_.pop();
            stack_.push(a+b);
            break;
        }
        case InstructionSet::MUL: {
            if (!stack_has(2)) break;
            int a = stack_.top();
            stack_.pop();
            int b = stack_.top();
            stack_.pop();
            stack_.push(a*b);
            break;
        }
        case InstructionSet::POP: {
            if (!stack_has(1)) break;
            stack_.pop();
            break;
        }
        case InstructionSet::LOAD: {
            if (!stack_has(1)) break;
            registers_[program_.at(++ip_)] = stack_.top();
            stack_.pop();
            break;
        }
        default: {
            std::cerr << "Error: Illegal OpCode Passed" << std::endl;
            running_ = false;
            break;
        }
    }
}