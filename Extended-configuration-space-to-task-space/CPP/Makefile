# Makefile for compiling all the elements of the mass matrix
#
#  ********************************************************
#  Variables
#
CXX = clang++
CXXFLAGS = -w -Ofast#-Wall -g -lm -lstdc++
SRf = dynamics_main.cpp
# Gather all the source files (.cpp) files requried to for compilation
SRC = dynamics_main.cpp
OBJS = $(SRC:.cpp=.o)
DEPS = dyn_funcs_test.h
MAIN = a
RM = rm -f
# *********************************************************
#test:
#	@echo $(SRC)
#	@echo $(OBJS)
$(MAIN):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(MAIN) -lgsl -lgslcblas

%.o: %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	$(RM) $(OBJS)
