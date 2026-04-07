# project/
# ├── Makefile
# ├── main.c
# ├── add.c
# ├── sub.c
# └── mathlib.h
# CC = gcc
# AR = ar
# CFLAGS = -Wall -Wextra -g

# LIB = libmymath.a
# OBJS = add.o sub.o
# TARGET = app

# all: $(LIB) $(TARGET)

# $(LIB): $(OBJS)
# 	$(AR) rcs $@ $^

# $(TARGET): main.o $(LIB)
# 	$(CC) main.o -L. -lmymath -o $@

# main.o: main.c mathlib.h
# 	$(CC) $(CFLAGS) -c main.c -o main.o

# add.o: add.c mathlib.h
# 	$(CC) $(CFLAGS) -c add.c -o add.o

# sub.o: sub.c mathlib.h
# 	$(CC) $(CFLAGS) -c sub.c -o sub.o

# clean:
# 	rm -f *.o *.a $(TARGET)

# .PHONY: all clean



# Why this is good
# %.o: %.c is a pattern rule
# $< is first prerequisite
# $@ is target
# $? updates archive with only newer object files
#This is a great lecture example 
#because it introduces incremental library updates.


CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -O2

LIB = libmymath.a
SRCS = add.c sub.c mul.c
OBJS = $(SRCS:.c=.o)
TARGET = app

all: $(LIB) $(TARGET)

$(LIB): $(OBJS)
	$(AR) rcs $@ $?

$(TARGET): main.o $(LIB)
	$(CC) $< -L. -lmymath -o $@

%.o: %.c mathlib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.a $(TARGET)

.PHONY: all clean