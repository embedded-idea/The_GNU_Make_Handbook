CC = gcc
CFLAGS = -Wall -Wextra -O2 -fPIC
LIB = libmymath.so
SRCS = add.c sub.c mul.c div.c
OBJS = $(SRCS:.c=.o)
TARGET = app

all: $(LIB) $(TARGET)

$(LIB): $(OBJS)
	$(CC) -shared -o $@ $^

$(TARGET): main.o $(LIB)
	$(CC) main.o -L. -lmymath -Wl,-rpath=. -o $@

%.o: %.c mathlib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.so $(TARGET)

.PHONY: all clean


# ✅ Step-by-step debugging method
# Step 1 — Dry run
# make -n

# 👉 What will run?
# Step 2 — Trace execution
# make --trace

# 👉 Which rules are used?
# Step 3 — Deep debug
# make -d

# 👉 Why is make deciding this?
# Step 4 — Print variables
# $(info VAR=$(VAR))

# Step 5 — Disable implicit rules
# make -r

# 👉 isolate problem
# Step 6 — Force rebuild
# make -B




# Debugging Makefiles is not about guessing — 
# it is about understanding how make thinks. 
# Once you learn how to trace rules, inspect variables, 
# and analyze dependencies, build failures become predictable and solvable. 
# This is the moment where you move from “trying things randomly” to engineering 
# with confidence.