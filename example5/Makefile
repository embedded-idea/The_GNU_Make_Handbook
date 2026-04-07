# app : main.o util.o utilc++.o
# 	gcc -o app main.o util.o

# # main.o : main.c
# # 	gcc -c main.c
# # util.o : util.c
# # 	gcc -c util.c

# # foo.o : foo.p
# #	@echo "hello" > foo.o
# #search "%.o: %."
# #%.o : %.c ; <command ......>;

# # %.o : %.c
# # 	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

# # main.o : main.c 
# # 	$(CC) -c $(CPPFLAGS) $(CFLAGS) main.c
# # util.o : util.c
# # 	$(CC) -c $(CPPFLAGS) $(CFLAGS) util.c
# utilc++.o : utilc++.cpp
# 	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) utilc++.cpp

# clean:
# 	rm -f main.o util.o utilc++.o app



# all:
# # Variables for Commands
# # AR: Archive (library) maintenance program. Default command is ar
# 	@echo $(AR)
# # AS: Assembler. Default command is as
# 	@echo $(AS)
# # CC: C compiler. Default command is cc
# 	@echo $(CC)
# # CXX: C++ compiler. Default command is g++
# 	@echo $(CXX)
# # CO: Program to extract files from RCS. Default command is co
# 	@echo $(CO)
# # CPP: C preprocessor (outputs to standard output). Default command is $(CC) -E
# 	@echo $(CPP)
# # FC: Fortran and Ratfor compiler and preprocessor. Default command is f77
# 	@echo $(FC)
# # GET: Program to extract files from SCCS. Default command is get
# 	@echo $(GET)
# # LEX: Lex lexical analyzer generator (for C or Ratfor). Default command is lex
# 	@echo $(LEX)
# # PC: Pascal compiler. Default command is pc
# 	@echo $(PC)
# # YACC: Yacc parser generator (for C programs). Default command is yacc
# 	@echo $(YACC)
# # MAKEINFO: Program to convert Texinfo source files (.texi) into Info files. Default command is makeinfo
# 	@echo $(MAKEINFO)
# # TEX: Program to generate TeX DVI files from TeX source. Default command is tex
# 	@echo $(TEX)
# # TEXI2DVI: Program to generate TeX DVI files from Texinfo source. Default command is texi2dvi
# 	@echo $(TEXI2DVI)
# # WEAVE: Program to convert WEB files into TeX. Default command is weave
# 	@echo $(WEAVE)
# # CWEAVE: Program to convert CWEB files into TeX. Default command is cweave
# 	@echo $(CWEAVE)
# # TANGLE: Program to convert WEB files into Pascal code. Default command is tangle
# 	@echo $(TANGLE)
# # CTANGLE: Program to convert CWEB files into C code. Default command is ctangle
# 	@echo $(CTANGLE)
# # RM: File deletion command. Default command is rm -f
# 	@echo $(RM)
# # # Variables for Command Arguments
# # # The following variables correspond to the parameters of the commands above.
# # # Unless otherwise specified, their default values are empty.
# # # ARFLAGS: Options for the archive program AR. Default is rv
# argumentsall:
# 	@echo $(ARFLAGS)
# # ASFLAGS: Options for the assembler (used when explicitly compiling .s or .S files)
# 	@echo $(ASFLAGS)
# # CFLAGS: Options for the C compiler
# 	@echo $(CFLAGS)
# # CXXFLAGS: Options for the C++ compiler
# 	@echo $(CXXFLAGS)
# # COFLAGS: Options for the RCS co command
# 	@echo $(COFLAGS)
# # CPPFLAGS: Options for the C preprocessor (also used by C and Fortran compilers)
# 	@echo $(CPPFLAGS)
# # FFLAGS: Options for the Fortran compiler
# 	@echo $(FFLAGS)
# # GFLAGS: Options for the SCCS get command
# 	@echo $(GFLAGS)
# # LDFLAGS: Options for the linker (e.g., ld)
# 	@echo $(LDFLAGS)
# # LFLAGS: Options for the Lex analyzer
# 	@echo $(LFLAGS)
# # PFLAGS: Options for the Pascal compiler
# 	@echo $(PFLAGS)
# # RFLAGS: Options for the Ratfor Fortran compiler
# 	@echo $(RFLAGS)
# # YFLAGS: Options for the Yacc parser generator
# 	@echo $(YFLAGS)








# all : app
# app : main.o util.o utilc++.o
# %.o : %.c
# 	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
# clean:
# 	rm -f main.o util.o utilc++.o app
#In the pattern rules described above, 
#both the targets and the prerequisites represent a set of files. 
#So how do we write a command that can generate the corresponding 
#targets from different prerequisite files?

#Since each time a pattern rule is applied, the targets and prerequisites may vary.
#Automatic variables are designed to solve this problem. Earlier, 
#we have already introduced them briefly, and by now you should have an intuitive
#understanding. Automatic variables automatically extract each file defined 
#in the pattern, one by one, until all files matching the pattern are processed.
# These variables are only valid within the command section of rules.
#Below is a list of all automatic variables and their meanings:

# Automatic Variables
#$@: Represents the target file(s) of the rule. In pattern rules, 
#if there are multiple targets, $@ refers to the set matched by 
#the target pattern.

# all: main.o util.o
# 	@echo Target is $@

# main.o: main.c
# 	@echo Building $@
# 	gcc -c main.c -o main.o

# util.o: util.c
# 	@echo Building $@
# 	gcc -c util.c -o util.o


#$%: Only meaningful when the target is an archive file. 
#It represents the member name within the archive.
#For example, if the target is libutil.a(util.o), then $% is util.o, 
#and $@ is libutil.a.
#If the target is not an archive file variable is empty.$%
# This is only used for archive targets like libutil.a(util.o).
# libutil.a(util.o): util.o
# 	@echo Archive file is $@
# 	@echo Member name is $%
# 	ar r libutil.a util.o
# If this rule is triggered:
# $@ = libutil.a
# $% = util.o





#$<: The name of the first prerequisite. 
#If the prerequisites are defined using a pattern (%), 
#then $< represents each matching file in turn.
# util.o: util.c
# 	@echo First prerequisite is $<
# 	gcc -c $< -o $@















#$?: The set of prerequisites that are newer than the target, 
#separated by spaces.
# libutil.a: main.o util.o
# 	@echo Updated prerequisites: $?
# 	ar r $@ $?













#$^: All prerequisites, separated by spaces. Duplicate entries are removed.
# app: main.o util.o main.o
# 	@echo All prerequisites without duplicates: $^
# 	gcc $^ -o $@
















#$+: Similar to $^, but does not remove duplicates.
# app: main.o util.o main.o
# 	@echo All prerequisites with duplicates: $+
# 	gcc $+ -o $@










#Pattern Stem Variable
#$*: Represents the stem matched by % in the target pattern.
# all: app
# app: main.o util.o

# %.o: %.c
# 	@echo Stem is $*
# 	@echo Source is $<
# 	@echo Target is $@
# 	gcc -c $< -o $@





#Each automatic variable can be modified with D or F:
#D → directory part
#F → file name part

# all: app
# app: main.o build/util.o
# #Directory (D) and File (F) Variants
# build/util.o: util.c
# 	@echo Target full name: $@
# 	@echo Target directory: $(@D)
# 	@echo Target file name: $(@F)
# 	gcc -c $< -o $@






#Directory and file parts of archive member names.
#$(<D), $(<F)
# all: app
# app: main.o build/util.o
# build/util.o: ../example5/util.c
# 	@echo First prerequisite full name: $<
# 	@echo First prerequisite directory: $(<D)
# 	@echo First prerequisite file: $(<F)
# 	gcc -c $< -o $@








#Directory and file parts of all prerequisites (duplicates keep).
#$(+D), $(+F)
# all: app
# app: build/util.o build/main.o
# 	@echo Directories with duplicates: $(+D)
# 	@echo Files with duplicates: $(+F)
# 	gcc $+ -o $@

# build/util.o: util.c
# 	@echo Building $@
# 	gcc -c $< -o $@
# build/main.o: main.c
# 	@echo Building $@
# 	gcc -c $< -o $@








#directories and file names of updated prerequisites
#$(?D), $(?F)
# all: app

# app:  libutil.a
# libutil.a: build/util.o build/a.o build/b.o build/c.o build/c.o
# 	@echo Updated prerequisite directories: $(?D)
# 	@echo Updated prerequisite files: $(?F)
# 	ar r $@ $?
# build/util.o: util.c
# 	@echo Building $@
# 	gcc -c $< -o $@
# build/a.o: a.c
# 	@echo Building $@
# 	gcc -c $< -o $@
# build/b.o: b.c
# 	@echo Building $@
# 	gcc -c $< -o $@
# build/c.o: c.c
# 	@echo Building $@
# 	gcc -c $< -o $@










#$(*D) and $(*F) — directory and file part of stem
# all: app
# app: build/main.o build/util.o
# build/%.o: ../example5/%.c
# 	@echo Stem full: $*
# 	@echo Stem directory: $(*D)
# 	@echo Stem file part: $(*F)
# 	gcc -c $< -o $@







#$(%D) and $(%F) — directory and file part of archive member
# libutil.a(build/util.o): build/util.o
# 	@echo Archive: $@
# 	@echo Member: $%
# 	@echo Member directory: $(%D)
# 	@echo Member file: $(%F)
# 	ar r libutil.a build/util.o

# build/util.o: util.c
# 	@echo Building $@
# 	gcc -c $< -o $@
















# Lex/Flex：生成词法分析器
# Yacc/Bison：生成语法分析器