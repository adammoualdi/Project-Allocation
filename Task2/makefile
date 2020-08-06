# First, as you can see, any line that begins with # is a comment.
#
# Second, make sure your makefile is actually called "makefile" or
# "Makefile". Don't call it by any other name, or with any suffix
# like Makefile.txt. It won't work.

# The following just specifies some variables for "flexibility".
# You may choose to directly write the compilation commands, as in the
# previous example.

# Specify the C++ compiler
CXX     = g++

# options to pass to the compiler. Here it sets the optimisation level,
# outputs debugging info for gdb, and C++ version to use.
CXXFLAGS = -O0 -g3 -std=c++14

# In each of the below, the line with a colon specifies a target to compile,
# and its dependencies are listed after the colon. It means if anything in
# the dependency list is changed, that target will be recompiled.
# The next line is the command to compile that target (or indeed to do
# anything).
# Note that the second line MUST BEGIN WITH A TAB (NOT SPACES).

# This simply allows "make all" to work
All: all
all: main

# In this more complicated example, there are many .cpp and .h files.
# All but one are compiled into its respective .o file (object file) using
# the -c flag.
# The final executable links all these object files together
main: main.cpp SupervisorClass.o ProjectsClass.o StudentClass.o Allocation.o
	$(CXX) $(CXXFLAGS) main.cpp SupervisorClass.o ProjectsClass.o StudentClass.o Allocation.o -o main

SupervisorClass.o: Supervisors.cpp SupervisorClass.h
	$(CXX) $(CXXFLAGS) -c Supervisors.cpp -o SupervisorClass.o

ProjectsClass.o: Projects.cpp ProjectsClass.h
	$(CXX) $(CXXFLAGS) -c Projects.cpp -o ProjectsClass.o

StudentClass.o: Students.cpp StudentClass.h
	$(CXX) $(CXXFLAGS) -c Students.cpp -o StudentClass.o

AllocationClass.o: Allocation.cpp Allocation.h
	$(CXX) $(CXXFLAGS) -c Allocation.cpp -o Allocation.o


# Some cleanup functions, invoked by typing "make clean" or "make deepclean"
deepclean:
	rm -f *~ *.o main *.exe *.stackdump

clean:
	-rm -f *~ *.o *.stackdump
