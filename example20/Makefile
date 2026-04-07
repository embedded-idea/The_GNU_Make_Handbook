# when Make is the better choice
# This is worth showing as code, not just theory.
# For a tiny utility:

# Make is simpler than CMake
# fewer moving parts
# easier to explain
# easier to debug
# This is a case where CMake may be overkill.

CC = gcc
CFLAGS = -O2
TARGET = tool

all: $(TARGET)

$(TARGET): tool.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean