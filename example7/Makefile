# project/
# ├── Makefile
# ├── main.c
# ├── add.c
# ├── sub.c
# └── mathlib.h

CC = gcc
CFLAGS = -Wall -Wextra -fPIC
LDFLAGS =

SHLIB = libmymath.so
OBJS = add.o sub.o mul.o div.o
TARGET = app

all: $(SHLIB) $(TARGET)

$(SHLIB): $(OBJS)
	$(CC) -shared -o $@ $^

$(TARGET): main.o $(SHLIB)
	$(CC) main.o -L. -lmymath -o $@

main.o: main.c mathlib.h
	$(CC) -Wall -Wextra -c main.c -o main.o

add.o: add.c mathlib.h
	$(CC) $(CFLAGS) -c add.c -o add.o
sub.o: sub.c mathlib.h
	$(CC) $(CFLAGS) -c sub.c -o sub.o
mul.o: mul.c mathlib.h
	$(CC) $(CFLAGS) -c mul.c -o mul.o
div.o: div.c mathlib.h
	$(CC) $(CFLAGS) -c div.c -o div.o

clean:
	rm -f *.o *.so $(TARGET)

.PHONY: all clean


#export LD_LIBRARY_PATH=/home/mzhang/home_work/classes_100_target/makefile/The_GNU_Make_Handbook/example7:$LD_LIBRARY_PATH
# Important teaching point
# For shared libraries, object files usually need:
# -fPIC
# That means position-independent code.
# And the library is linked with:
# gcc -shared -o libmymath.so add.o sub.o mul.o div.o