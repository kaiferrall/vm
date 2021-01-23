cmake_minimum_required(VERSION 3.17)
project(vm)

set(CMAKE_CXX_STANDARD 14)

add_executable(vm main.cpp stack-vm.h stack-vm.cpp)