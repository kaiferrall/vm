//
// Created by Kai Ferrall on 2021-01-22.
//

#include "stack-vm.h"
StackVM::StackVM() {
    mem.reserve(1000000);
}

i32 StackVM::getType(i32 instr) {
    i32 typeSelect = 0xc0000000;
    type = (typeSelect & instr) >> 30;
    return type;
}

i32 StackVM::getData(i32 instr) {
    i32 dataSelect = 0x3fffffff;
    data = dataSelect & instr;
    return data;
}

void StackVM::fetch() {
    pc++;
}

void StackVM::decode() {
    type = getType(mem[pc]);
    data = getData(mem[pc]);
}

void StackVM::execute() {
    if (type == 0 || type == 2) {
        sp++;
        mem[sp] = data;
    } else {
        executePrimitive();
    }
}

void StackVM::executePrimitive() {
    switch (data) {
        case 0:
            std::cout << "Halt" << std::endl;
            running = 0;
            break;
        case 1:
            std::cout << "Add: " << mem[sp - 1] << " " << mem[sp] << std::endl;
            mem[sp - 1] = mem[sp] + mem[sp - 1];
            sp--;
            break;
    }
}

void StackVM::run() {
    pc -= 1;
    while (running == 1) {
        fetch();
        decode();
        execute();
        std::cout << "TOS: " << mem[sp] << std::endl;
    }
}

void StackVM::loadProgram(std::vector<i32> prog) {
    for (i32 i = 0; i < prog.size(); i++) {
        mem[pc + i] = prog[i];
    }
}