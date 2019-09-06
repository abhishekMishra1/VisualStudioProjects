CC = g++
CCFLAGS = -Wall

EXEC = run
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	
clean:
	rm -f $(EXEC) $(OBJECTS)
	
#graphicalNode: Source.o WindowsLayout.o NodeLayout.o
#	$(CC) $(CCFLAGS) $?	-o $@
	
#Source.o: Source.cpp
#	$(CC) -c Source.cpp
	
#WindowsLayout.o: WindowsLayout.cpp WindowsLayout.h
#	$(CC) -c WindowsLayout.cpp WindowsLayout.h
	
#NodeLayout.o: NodeLayout.cpp NodeLayout.h
#	$(CC) -c NodeLayout.cpp NodeLayout.h