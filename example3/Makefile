#$(<function> <arguments>)
#${<function> <arguments>}

#$(subst FROM,TO,TEXT)
#FROM: string to be replaced
#TO: replacement string
#TEXT: the input text
# COMMA := ,
# EMPTY :=
# SPACE := $(EMPTY) $(EMPTY)

# ORIGINALTEXT := A B C
# TARGETTEXT := $(subst $(SPACE),$(COMMA),$(ORIGINALTEXT))


#String Functions
#subst
#patsubst
#strip
#findstring
#filter
#filter-out
#sort
#word
#wordlist
#words
#firstword

#File or Folder (file path) Functions
#dir		$(dir names)	Return the directory portion of each path
#notdir		$(notdir names)	Return the filename portion of each path
#suffix		$(suffix names)	Return the file extension of each filename
#basename	$(basename names)	Return the filename without its extension
#addsuffix	$(addsuffix suffix,names)	Append a suffix to each word
#addprefix	$(addprefix prefix,names)	Prepend a prefix to each word
#join		$(join list1,list2)	Concatenate corresponding words from two lists
#wildcard	$(wildcard pattern)	Return a list of existing files matching the pattern
#realpath	$(realpath names)	Return the absolute path (resolves symbolic links)
#abspath	$(abspath names)	Return the absolute path (does not resolve symbolic links)


#conditional funcions
#if	$(if cond,then,else)	If cond is non-empty return then, 
#otherwise return else

#or	$(or cond1,cond2,...)	Return the first non-empty value from left to right

#and	$(and cond1,cond2,...)	Return the last value if all are non-empty, 
#otherwise return empty

#intcmp	$(intcmp a,b,lt,eq,gt)	Compare two integers; return lt (less than), 
#eq (equal), or gt (greater than) accordingly

#Loop Function
#foreach	$(foreach var,list,text)	
#Iterate over each element in list, assign it to var, and expand text




#File I/O Function
#file	$(file op,filename,text)	
#Read/write files; op can be > (overwrite), >> (append), or < (read)

# Overwrite file
#$(file >output.txt,hello world)    # Write "hello world" to output.txt

# Append to file
#$(file >>output.txt,more content)  # Append content to output.txt

# Read file
#$(file <input.txt)                 # Read and return contents of input.txt




#Variable Inspection Functions

#value	$(value var)	Return the raw unexpanded value of a variable
#origin	$(origin var)	Return the source/origin of a variable
#flavor	$(flavor var)	Return the type of a variable

#$(value var)	Return the raw unexpanded value of a variable

#$(origin) Return Values:
#undefined		->Variable is not defined
#default		->Makefile built-in default variable
#environment	->Comes from a system environment variable
#file			->Defined inside a Makefile
#command line	->Passed in via command-line argument
#override		->Defined using the override keyword
#automatic		->An automatic variable (e.g. $@, $<)


#$(flavor) Return Values:
#undefined		->Variable is not defined
#recursive		->Recursively expanded variable (defined with =, expanded at use time)
#simple			->Simply expanded variable (defined with :=, expanded at definition time)


#Control Flow Functions
#error		$(error text)	Print error message and immediately terminate the build
#warning	$(warning text)	Print warning message and continue the build
#info		$(info text)	Print informational message and continue the build


#Shell Function
#shell	$(shell command)	Execute a shell command and return its output to Makefile


#call Function (Invoke Custom Macros)
#call	$(call var,param1,param2,...)	Invoke a custom macro; $(1), $(2) correspond to each passed argument


#eval Function (Dynamic Execution)
#eval	$(eval text)	Dynamically parse and execute text as Makefile code



#$(patsubst <pattern>,<replacement>,<text>)
#TARGETTEXT := $(patsubst %.c,%.o, a.c b.c c.c)

#$(strip <string>)
#TARGETTEXT := $(strip aa     dd    cc)

#$(findstring <find>,<in>)
#TARGETTEXT := $(findstring a,a b c)

#$(filter <pattern...>,<text>)
#SRC := abc.c xyz.c ooo.s haha.h
#TARGETTEXT:= $(filter %.c %.s,$(SRC))

#$(filter <pattern...>,<text>)
#SRC := abc.c xyz.c ooo.s haha.h
#TARGETTEXT:= $(filter-out %.c %.s,$(SRC))

#$(sort <list>)
#TARGETTEXT := $(sort nnn ccc jjj ddd)

#$(word <n>,<text>)
#TARGETTEXT := $(word 2, nnn ccc jjj ddd)

#$(wordlist <s>,<e>,<text>)
#TARGETTEXT := $(wordlist 2,3, ttt nnn jjj ddd)

#$(words <text>)
#TARGETTEXT := $(words ttt nnn jjj ddd)

#$(firstword <text>)
#TARGETTEXT := $(firstword ttt nnn jjj ddd)



# dir: get directory portion
#TARGETTEXT := $(dir /home/user/file.c)#      →  "/home/user/"

# notdir: get filename portion
#TARGETTEXT := $(notdir /home/user/file.c)#   →  "file.c"

# suffix: get file extension
#TARGETTEXT := $(suffix file.c file.o)#       →  ".c .o"

# basename: get filename without extension
#TARGETTEXT := $(basename /home/user/file.c)# →  "/home/user/file"

# addsuffix: append suffix
#TARGETTEXT := $(addsuffix .c,foo bar)#       →  "foo.c bar.c"

# addprefix: prepend prefix
#TARGETTEXT := $(addprefix src/,foo bar)#     →  "src/foo src/bar"

# join: concatenate two lists
#TARGETTEXT := $(join a b,c d)#               →  "ac bd"

# wildcard: get actually existing files
#TARGETTEXT := $(wildcard *.c)#               →  "main.c util.c"

# realpath: get absolute path (resolves symlinks)
#TARGETTEXT := $(realpath ../example3/symlink.c)#     →  "/home/mzhang/home_work/classes_100_target/makefile/The_GNU_Make_Handbook/example3/main.c"

# abspath: get absolute path (no symlink resolution)
#TARGETTEXT := $(abspath ../example3/symlink.c)#      →  "/home/mzhang/home_work/classes_100_target/makefile/The_GNU_Make_Handbook/example3/main.c"




# if: conditional check
#TARGETTEXT :=$(if hello,yes,no)                    #→  "yes"   # condition non-empty, return then
#TARGETTEXT :=$(if ,yes,no)                         #→  "no"    # condition empty, return else

# or: return first non-empty value
#TARGETTEXT :=$(or ,,,hello,world)                  #→  "hello"

# and: return last value only if all are non-empty
#TARGETTEXT :=$(and hello,world)                    #→  "world" # all non-empty
#TARGETTEXT :=$(and hello,,world)                   #→  ""      # has empty value, return empty

# intcmp: integer comparison
#TARGETTEXT :=$(intcmp 3,5,less,equal,greater)      #→  "less"
#TARGETTEXT :=$(intcmp 5,5,less,equal,greater)      #→  "equal"
#TARGETTEXT :=$(intcmp 7,5,less,equal,greater)      #→  "greater"


#loop function
# foreach: iterate over a list
#TARGETTEXT := $(foreach x,a b c,$(x).o)    #→  "a.o b.o c.o"

# Practical use: get all .c files across multiple directories
#DIRS = src lib test #this is not exisited
#TARGETTEXT1 := $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
#Returns list of all .c files found in each directory




# Overwrite file
#TARGETTEXT := $(file >output.txt,hello world)    # Write "hello world" to output.txt

# Append to file
#TARGETTEXT := $(file >>output.txt,more content)  # Append content to output.txt

# Read file
#TARGETTEXT := $(file <input.txt)                 # Read and return contents of input.txt


# Variable Inspection Functions
# value: get raw unexpanded value
#VAR1 = AA
#VAR2 = $(VAR1)
#TARGETTEXT := '$(value VAR2)'# "$(VAR1)"  # returns raw value, not expanded
#TARGETTEXT := $(VAR2)# "" # expanded: VAR2 is empty, returns empty

# origin: get variable source
#TARGETTEXT := $(origin CC)# "default"      # CC is a Makefile built-in default
#TARGETTEXT := $(origin PATH)#  →  "environment"  # PATH comes from system environment

# flavor: get variable type
#VAR1 = hello     # recursively expanded variable
#VAR2 := world    # simply expanded variable
#VAR3 ?= who    # recursive
#VAR4 += are    # recursive
#TARGETTEXT := $(flavor VAR1)# "recursive"
#TARGETTEXT := $(flavor VAR2)# "simple"
#TARGETTEXT := $(flavor VAR3)# "recursive"
#TARGETTEXT := $(flavor VAR4)# "recursive"
#TARGETTEXT := $(flavor VAR5)# "undefined"

#Control Flow Functions
#TARGETTEXT := $(error Build failed, required file is missing)  # Print error and terminate
#TARGETTEXT := $(warning This variable will be deprecated soon) # Print warning, keep going
#TARGETTEXT := $(info Currently compiling module A)             # Print info, keep going

#TARGETTEXT := $(shell date)#           →  "Thu 26 Mar 2026 04:15:33 PM PDT"  # Get current time
#TARGETTEXT := $(shell ls *.c)#         →  "main.c  symlink.c  util.c"             # List all .c files
#TARGETTEXT := $(shell echo $(PATH))#   →  "/home/mzhang/.config/Code/User/globalStorage/github.copilot-chat/debugCommand:/home/mzhang/.config/Code/User/globalStorage/github.copilot-chat/copilotCli:/home/mzhang/.cargo/bin:/home/mzhang/.local/bin:/home/mzhang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin"    # Get PATH variable

#call Function (Invoke Custom Macros)
# Define macros
HI = $(1)
GREET  = Hello, $(1)! You are $(2) years old.

# Invoke macros
#TARGETTEXT := $(call HI,hello)#         →  "hello"
#TARGETTEXT := $(call GREET,Tom,18)#         →  "Hello, Tom! You are 18 years old."


FILES = file1 file2 file3
define GEN_RULE
$(1):
	@echo building $(1)
endef
#$(foreach f,$(FILES),$(eval $(call GEN_RULE,$(f))))

file1:
	@echo building file1
file2:
	@echo building file2
file3:
	@echo building file3


all:
	@echo $(TARGETTEXT)
#	@echo $(TARGETTEXT1)
#	@echo $(DIRS)

