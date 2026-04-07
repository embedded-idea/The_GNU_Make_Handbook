#pattern rules
#automatic variables
#scalable structure
#This is where Make becomes educationally powerful.

CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = app
SRCS = main.c mathlib.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c mathlib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean