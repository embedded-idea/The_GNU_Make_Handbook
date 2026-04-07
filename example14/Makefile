# static library
# libraries
# ar
# linker flags
# reusable code
CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -O2

LIB = libmymath.a
OBJS = mathlib.o
TARGET = app

all: $(LIB) $(TARGET)

$(LIB): $(OBJS)
	$(AR) rcs $@ $^

$(TARGET): main.o $(LIB)
	$(CC) main.o -L. -lmymath -o $@

main.o: main.c mathlib.h
	$(CC) $(CFLAGS) -c $< -o $@

mathlib.o: mathlib.c mathlib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a $(TARGET)

.PHONY: all clean