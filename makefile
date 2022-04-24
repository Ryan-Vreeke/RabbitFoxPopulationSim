# the compiler: g++ for c++ program
CC= g++

#compiler flags:
#	-g adds debugging information to the executable file
#	-Wall turns on most, but not all, compiler warnings

CFLAGS = -g -Wall

EcoSim: EcoSim.cpp
	$(CC) $(CFLAGS) -o EcoSim EcoSim.cpp