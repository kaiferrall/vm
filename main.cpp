#include "stack-vm.h"

int main() {
    StackVM vm;
    std::vector<i32> program{3, 4, 0x40000001, 0x40000000};
    vm.loadProgram(program);
    vm.run();
    return 0;
}
