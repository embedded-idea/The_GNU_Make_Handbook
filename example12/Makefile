#debug vs release build

#This is very important in real engineering.
#make MODE=debug
#make MODE=release

CC = gcc
TARGET = app
SRCS = main.c mathlib.c
OBJS = $(SRCS:.c=.o)

MODE ?= debug

CFLAGS = -Wall -Wextra
ifeq ($(MODE),debug)
	CFLAGS += -O0 -g -DDEBUG
else ifeq ($(MODE),release)
	CFLAGS += -O2 -DNDEBUG
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c mathlib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean