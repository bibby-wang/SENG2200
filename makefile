CC=g++
CFLAGS=-c -Wall 
LDFLAGS=
SOURCES=dclink.h DCLink.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=b.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
	rm -rf *.o core
	
%.o : %.cpp
	$(CC) $(CFLAGS) -c $<
	
r:
	./b.exe
	
clean:
	rm -rf *.o core

