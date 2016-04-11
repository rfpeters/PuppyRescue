# Author: Ryan Peters
# Date: 12/06/15
# Description: makefile for a text adventure were you rescue
#    a dog.
all:
	g++ Hallway.cpp Study.cpp Library.cpp Kitchen.cpp Bedroom.cpp main.cpp -o DogRescue

clean:
	rm *.o a.out a.exe