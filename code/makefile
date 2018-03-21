CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Point.cpp testmain.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=A1.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

	rm -rf *.o core
	
%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
