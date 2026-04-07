# cmake -S . -B build
# Still clean and nice.
# CMake starts feeling better when the project grows.
cmake_minimum_required(VERSION 3.10)
project(app C)

add_executable(app main.c mathlib.c)
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(app PRIVATE -Wall -Wextra -O2)