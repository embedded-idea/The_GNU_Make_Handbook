#out-of-source build
# Make absolutely can support out-of-source builds.
# This is important because some students wrongly think only CMake can do this.
CC = gcc
CFLAGS = -Wall -Wextra -O2
BUILD_DIR = build
TARGET = $(BUILD_DIR)/app
SRCS = main.c mathlib.c
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

$(BUILD_DIR)/%.o: %.c mathlib.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean