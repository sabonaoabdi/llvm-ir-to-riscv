#pragma once
#include <array>
#include <stack>
#include <vector>

class VM {
    public:
    enum InstructionSet { 
        PSH,  // 00000000
        ADD,  // 00000001
        MUL,  // 00000010
        POP,  // 00000011
        LOAD, // 00000100
        HLT,  // 00000101
    };
    enum Registers {
        x0,                                                 // constant 0
        x1,  x2,  x3,  x4,
        x5,  x6,  x7,
        x8,  x9,
        x10, x11,
        x12, x13, x14, x15,
        x16, x17,
        x18, x19, x20, x21, x22, x23, x24, x25, x26, x27,
        x28, x29, x30, x31
    };

    explicit VM(std::vector<uint32_t> program);
    void run();
    void register_dump() const;
    int get_register(Registers r) const;

    private:
    int decode_instr() const;
    bool stack_has(std::size_t n);
    void eval_instr(int instr);
    std::vector<uint32_t> program_;
    std::stack<int> stack_;
    std::array<int, 32> registers_ {};
    int ip_ = 0;
    bool running_ = true;
};

