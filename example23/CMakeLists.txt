cmake_minimum_required(VERSION 3.10)
project(app C)

add_executable(tool tool.c)
target_include_directories(tool PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(tool PRIVATE -Wall -Wextra -O2)
