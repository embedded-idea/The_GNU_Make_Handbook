#when CMake is the better choice
# CMake becomes attractive when you have:
# many targets
# many platforms
# IDE integration
# installation rules
# package discovery
# external dependencies
cmake_minimum_required(VERSION 3.10)
project(bigproj C)

add_library(core STATIC core.c)
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(app1 app1.c)
target_link_libraries(app1 PRIVATE core)

add_executable(app2 app2.c)
target_link_libraries(app2 PRIVATE core)

add_executable(test_core test_core.c)
target_link_libraries(test_core PRIVATE core)