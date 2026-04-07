# After executing the make command, 
#there are three possible exit codes:
# 0 Indicates successful execution.
# 1 Returned if any error occurs 
#during the execution of make.
# 2 Returned if the -q option is 
#used and make determines that some targets do 
#not need to be updated.


# all:
# 	@echo "Build successful"
# all:
# 	gcc main.c -o app
# all
# 	@echo missing colon
# all:
# 	gcc not_exist.c -o app
# all:
# 	$(error Something is wrong!)



# -B, --always-make Unconditionally make 
# all targets.

# all: hello.txt

# hello.txt:
# 	@echo "Building hello.txt..."
# 	@echo "hello world" > hello.txt


# -j [N], --jobs[=N]      Allow N jobs at once; 
# infinite jobs with no arg.
#         app
#        /   \
#     main.o  util.o
#If two targets are independent, 
#they can run in parallel


# -d or --debug 
# What kind of information does it show?
# When you run with -d, make prints:
# 1 Dependency analysis
# Considering target file 'app'
# Looking for dependencies...

# 2 Timestamp decisions
# File 'main.o' is older than 'main.c'
# needs rebuild

# 3 Rule matching
# Trying implicit rule...
# Trying pattern rule...

# 4 Why something is (or is not) rebuilt
# No need to remake target 'util.o'


#Simulating builds safely with -n (dry run) 
#-n, --just-print, --dry-run

#-k, --keep-going            
#Keep going when some targets can't be made.
#-i, --ignore-errors         
#Ignore errors from recipes.

#-e, --environment-overrides

#Managing directories and files (-C, -f, -I)
#-C DIRECTORY, --directory=DIRECTORY
#Change to DIRECTORY before doing anything.
#-f FILE, --file=FILE, --makefile=FILE
#Read FILE as a makefile.
#-I DIRECTORY, --include-dir=DIRECTORY
#Search DIRECTORY for included makefiles.

#Inspect Everything Inside Make
#-p, --print-data-base       
#Print make's internal database.

#Understanding performance and system load (-l) 
#-l [N], --load-average[=N], --max-load[=N]
# Don't start multiple jobs unless load is 
# below N.

#Synchronizing output in parallel builds (-O) 
#starts parallel jobs
#captures each job’s stdout/stderr
#waits until a synchronization boundary
#prints the buffered output as one block
#So instead of every line 
#going straight to the terminal immediately, 
#make organizes it first.


#--trace for execution tracing 
#--warn-undefined-variables for catching hidden bugs


#-r(no built-in rules) and 
#-R(no built-in variables) 
#for disabling built-in behaviors 
# ==============================
# Pattern Rule Makefile Example
# ==============================

# Compiler
CC = gcc
# Compile flags
CFLAGS = -Wall -Wextra -O2
# Link flags
LDFLAGS =
# Target program
TARGET = app
# Source files
SRCS = main.c util.c
# Automatically generate object files
OBJS = $(SRCS:.c=.o)
# Default target
all: $(TARGET)
# Link step
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)
# ==============================
# Pattern Rule (core part)
# ==============================
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@
# Clean
clean:
	rm -f $(OBJS) $(TARGET)
# Rebuild
rebuild: clean all
# Phony targets
.PHONY: all clean rebuild

	






#CC = gcc
# CFLAGS = -Wall -O2
# # include config.mk
# all: app

# app: main.o util.o
# 	echo "first"
# 	$(CC) main.o util.o -o app

# main.o: main.c
# 	$(CC) $(CFLAGS) -c main.c
# #	false

# util.o: util.c
# 	$(CC) $(CFLAGS) -c util.c

# clean:
# 	rm -rf *.o app


