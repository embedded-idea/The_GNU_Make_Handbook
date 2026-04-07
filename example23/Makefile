# Make concepts still matter in CMake projects
# Makefile idea

CC = gcc

CFLAGS = -Wall -Wextra -O2
TARGET = tool
SRCS = tool.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean