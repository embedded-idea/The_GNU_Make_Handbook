# 1. First: the core idea students must understand

# Before examples, make this clear:
# Make = a build tool
# CMake = a build system generator
# Ninja = a fast build executor

# That means:
# Make can read a Makefile and build
# CMake usually generates build files for another tool
# Ninja usually reads build.ninja and builds very fast


# CMake -> generates -> Makefiles to Make
# CMake -> generates -> Ninja files to Ninja
# Make / Ninja -> actually build tools

#That single idea removes a lot of confusion.

# example 1
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = hello

all: $(TARGET)

$(TARGET): main.o
	$(CC) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main.o $(TARGET)

.PHONY: all clean



# 2. Then: the example
# This example is a more complete Makefile 
# for a C project with multiple source files, header files, 
# and build configurations (debug/release). 
# It also includes support for cross-compilation.
