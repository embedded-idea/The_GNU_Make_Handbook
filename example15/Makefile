# shared library
# Make handles this well too.
# Very explicit. Very educational.
CC = gcc
CFLAGS = -Wall -Wextra -O2 -fPIC

SHLIB = libmymath.so
TARGET = app

all: $(SHLIB) $(TARGET)

$(SHLIB): mathlib.o
	$(CC) -shared -o $@ $^

$(TARGET): main.o $(SHLIB)
	$(CC) main.o -L. -lmymath -Wl,-rpath=. -o $@

main.o: main.c mathlib.h
	$(CC) -Wall -Wextra -O2 -c $< -o $@

mathlib.o: mathlib.c mathlib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.so $(TARGET)

.PHONY: all clean