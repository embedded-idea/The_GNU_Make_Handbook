# CMake is very elegant for libraries.
# cmake -S . -B build
# cmake --build build
cmake_minimum_required(VERSION 3.10)
project(app C)

add_library(mymath STATIC mathlib.c)
target_include_directories(mymath PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(app main.c)
target_link_libraries(app PRIVATE mymath)