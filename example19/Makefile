#Make as task runner
# This is a powerful chapter example because Make is often useful even 
# when it is not the “main” build system.

# Even when a project uses CMake, Make is still great for:
# shortcuts
# testing
# formatting
# packaging
# flashing firmware
# deployment tasks
APP = app

build:
	gcc main.c mathlib.c -o $(APP)

run: build
	./$(APP)

test: build
	./test.sh

format:
	clang-format -i *.c *.h

clean:
	rm -f $(APP)

.PHONY: build run test format clean