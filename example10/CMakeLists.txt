# cmake -S . -B build
# cmake --build build
cmake_minimum_required(VERSION 3.10)
project(hello C)

add_executable(hello main.c)
target_compile_options(hello PRIVATE -Wall -Wextra -O2)