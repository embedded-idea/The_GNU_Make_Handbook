#Make calling CMake
#make and cmake are friends, not enemies.
#Make can call CMake, and CMake can call Make.
#This is a common pattern in real projects.

# Even in modern projects, teams often keep a tiny Makefile as a convenience layer
#.
# So students should not think:
# old = Make
# new = no Make
# Real projects often mix tools.

BUILD_DIR = build

all:
#	cmake -S . -B $(BUILD_DIR)
	ninja
#	cmake --build $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean