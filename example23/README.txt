# Student misconception
# “CMake replaces Make.”
# example:
# CMake generates Makefiles
# cmake -S . -B build -G "Unix Makefiles"
# cmake --build build
# CMake generates Ninja files
# cmake -S . -B build -G Ninja
# cmake --build build
# CMake does not directly replace Make in a simple one-to-one way.
# It often uses Make or Ninja underneath.


# Different syntax, same core concept:
#     • targets 
#     • dependencies 
#     • compilation 
#     • linking 
#     • incremental rebuilds 
# Modern tools still rely on the same build logic ideas.


#LAST
#Make, CMake, and Ninja are not enemies. 
#They solve different layers of the build problem. 
#Make is direct and powerful. CMake is a generator and 
#project description layer. Ninja is a fast executor. 
#Great engineers do not ask which tool is “best” in the abstract 
#they ask which tool fits the project, the team, and the workflow.