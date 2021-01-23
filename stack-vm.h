//
// Created by Kai Ferrall on 2021-01-22.
//

#ifndef VM_STACK_VM_H
#define VM_STACK_VM_H

#include "iostream"
#include "vector"

// 32 bit instructions
typedef int32_t i32;

class StackVM {
    // program counter
    i32 pc = 100;
    // stack pointer
    i32 sp = 0;
    // memory set
    std::vector<i32> mem;
    i32 type = 0;
    i32 data = 0;
    i32 running = 1;

    i32 getType(i32 instr);
    i32 getData(i32 instr);
    void fetch();
    void decode();
    void execute();
    void executePrimitive();

    public:
    StackVM();
    void run();
    void loadProgram(std::vector<i32> prog);

};

#endif //VM_STACK_VM_H
