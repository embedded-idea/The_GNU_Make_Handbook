
# CMake has built-in support for build types.
# That is convenient for medium and large projects.
# cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
# cmake --build build-debug 

# cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
# cmake --build build-release

#Debug	For debugging	-O0 -g
#Release	Optimized for speed	-O2/-O3 -DNDEBUG

cmake_minimum_required(VERSION 3.10)
project(app C)

add_executable(app main.c mathlib.c)
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(app PRIVATE -Wall -Wextra)