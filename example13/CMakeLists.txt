
# cmake -S . -B build
# cmake --build build
# Out-of-source build is a natural default in CMake workflows.
cmake_minimum_required(VERSION 3.10)
project(app C)

add_executable(app main.c mathlib.c)
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})