
# # : # =  
# # foo FOO MakeFlags 
# # $< $@ 
# # () {}
# # "$" <- "$$"

# # main four assignment types = := ?= +=

# # Makefile example for four assignment types
# # Usage: just run 'make' to see all output

# # 1. Recursive assignment = (lazy expansion) 
# # Feature: Expanded only when referenced; can refer to variables defined later
# VAR1 = Hello $(VAR2)  # VAR2 is undefined here, but no error
# VAR2 = World          # VAR1 will resolve VAR2 recursively when used
# test_eq:
# 	@echo "===== Recursive assignment = ====="
# 	@echo "VAR1 = $(VAR1)"  # Output: VAR1 = Hello World

# # ==================== 2. Simple assignment := (immediate expansion) ====================
# # Feature: Expanded immediately at assignment; uses only variables already defined
# VAR3 := Hi $(VAR4)    # VAR4 is undefined, so expands to empty
# VAR4 := There         # Later definition does NOT affect VAR3

# test_colon_eq:
# 	@echo -e "\n===== Simple assignment := ====="
# 	@echo "VAR3 = $(VAR3)"  # Output: VAR3 = Hi 
# 	@echo "VAR4 = $(VAR4)"  # Output: VAR4 = There

# # ==================== 3. Conditional assignment ?= (default value) ====================
# # Feature: Assigns only if variable is NOT previously defined; skips if already set
# VAR5 ?= Default Value  # VAR5 is undefined, so assigned
# VAR6 = Exists Value    # VAR6 already has a value
# VAR6 ?= New Value      # This assignment is ignored

# test_qmark_eq:
# 	@echo -e "\n===== Conditional assignment ?= ====="
# 	@echo "VAR5 = $(VAR5)"  # Output: VAR5 = Default Value
# 	@echo "VAR6 = $(VAR6)"  # Output: VAR6 = Exists Value

# # ==================== 4. Appending assignment += (extend variable) ====================
# # Feature: Appends content to the variable; automatically inserts a space
# VAR7 = main.o# Initial object files
# VAR7 += add.o sub.o		# Append more object files

# test_plus_eq:
# 	@echo -e "\n===== Appending assignment += ====="
# 	@echo "VAR7 = $(VAR7)"  # Output: VAR7 = main.o add.o sub.o
	
# VAR8 = c
# main.o : main.${VAR8}
# 	${VAR8}${VAR8} -${VAR8} main.${VAR8}

# # main.o : main.c
# # cc -c main.c

# VARA = $(VARB)
# VARB = $(VARC)
# VARC = VARD?
# all:
# 	echo $(VARA)

# CFLAGS = $(include_dirs) -O
# include_dirs = -I(VARA) -I(VARB) -Ixxx 

# CFLAGS = $(CFLAGS) -O

# A = $(B)
# B = $(A)
# wildcard or shell

# VARA := something1
# VARB := $(VARA) somethingelse
# VARA := something2

# ifeq (0,${MAKELEVEL})
# cur-dir := $(shell pwd)
# whoami := $(shell whoami)
# host-type := $(shell arch)
# MAKE := ${MAKE} host-type=${host-type} whoami=${whoami}
# endif

# EMPTYSTRING :=
# SPACE :=$(EMPTYSTRING) # end of the line
# dir :=/var/tmp
# # directory to put the xxx in dir = "/var/tmp    "  
# $(dir)/file ->"/var/tmp/file"

# app : main.o add.o sub.o mul.o div.o eat.o \
# 	play.o study.o sleep.o 
# 	gcc -o app main.o add.o sub.o mul.o div.o \
# 	 eat.o play.o study.o sleep.o

# main.o : main.c main.h
# 	gcc -c main.c
# add.o : add.c add.h main.h
# 	gcc -c add.c
# sub.o : sub.c sub.h main.h
# 	gcc -c sub.c
# mul.o : mul.c mul.h main.h
# 	gcc -c mul.c
# div.o : div.c div.h main.h
# 	gcc -c div.c
# eat.o : eat.c eat.h main.h
# 	gcc -c eat.c
# play.o : play.c play.h main.h
# 	gcc -c play.c
# study.o : study.c study.h main.h
# 	gcc -c study.c
# sleep.o : sleep.c sleep.h main.h
# 	gcc -c sleep.c

# clean :
# 	rm app main.o add.o sub.o mul.o \
# 	div.o eat.o play.o study.o sleep.o

#$(var:a=b) or ${var:a=b}
# VAR1 := main.o add.o sub.o
# VAR2 := $(VAR1:%.o=%.c)

# # VAR1 := main.o add.o sub.o
# # VAR2 := $(VAR1:.o=.c)

# all:
# 	echo "VAR1 = $(VAR1) and VAR2 = $(VAR2)"

# VAR1 = VAR2
# VAR2 = hello
# VAR3 := $($(VAR1)) #$(VAR2) -> hello

# all:
# 	@echo "VAR1 = $(VAR1) and VAR2 = $(VAR2) and VAR3 = $(VAR3)"


# FIRST_SECOND = Hello
# VAR1 = FIRST#
# VAR2 = SECOND#
# all:
# 	@echo FIRST_SECOND = $($(VAR1)_$(VAR2))

# VAR1 = b
# a_objects := maina.o adda.o suba.o
# b_objects := mainb.o addb.o subb.o
# SOURCES := $($(VAR1)_objects:.o=.c)
# all:
# 	@echo SOURCES = $(SOURCES)




#override
#override VAR1 = ABCD
#override VAR1 := ABCD
#override VAR1 ?= ABCD
# override VAR1 += ABCD
# all:
# 	@echo $(VAR1)



# define MESSAGE
# Hello
# This is a multi-line
# try me
# endef

# all:
# 	$(info $(MESSAGE))

# VAR1 = main
# override define BUILD_TEMPLATE
# echo "Compiling $(1)..."
# gcc $(1).c -o $(1)
# echo "Done!"
# endef

# all:
# 	$(info $(BUILD_TEMPLATE))

# app:
# 	$(call BUILD_TEMPLATE,main)


#Environment Variables 
#run the command in shell 
#export VAR1="-O2 -Wall from ENV"

# VAR1="-O2 -Wall frome makefile"
# all:
# 	@echo "VAR1 = $(VAR1)"


#target : VARIABLE = value
#target : override VARIABLE = value
#target : VARIABLE := value
#target : VARIABLE += value
#target : VARIABLE ?= value

# CFLAGS = -O2   # global

# main : CFLAGS = -g   # local
# main : override CFLAGS = -g
# main : CFLAGS := -g
# main : CFLAGS += -g
# main : CFLAGS ?= -g

# main : main.o add.o sub.o
# 	$(CC) $(CFLAGS) main.o add.o sub.o

# main.o : main.c
# 	$(CC) -c $(CFLAGS) main.c

# add.o : add.c
# 	$(CC) -c $(CFLAGS) add.c

# sub.o : sub.c
# 	$(CC) -c $(CFLAGS) sub.c




#<pattern ...> : <variable-assignment>
#<pattern ...> : override <variable-assignment>


CFLAGS = -g   # global 
%.o : CFLAGS = -O2 # pattern

all: main.o add.o
	$(CC) $(CFLAGS) -o main main.o add.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

add.o: add.c
	$(CC) $(CFLAGS) -c add.c