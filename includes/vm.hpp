#ifndef VM_HPP
#define VM_HPP

#include <array>
#include <stack>
#include <vector>

class VM {
    public:
    enum InstructionSet { PSH, ADD, MUL, POP, LOAD, HLT };
    enum Registers { A, B, C, D, E };

    explicit VM(std::vector<int> program);
    void run();
    void register_dump() const;
    int get_register(Registers r) const;

    private:
    int fetch_instr() const;
    bool stack_has(std::size_t n);
    void eval_instr(int instr);
    std::vector<int> program_;
    std::stack<int> stack_;
    std::array<int, 5> registers_ {};
    int ip_ = 0;
    bool running_ = true;
};

#endif