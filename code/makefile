CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Polygon.cpp Point.cpp MyPolygons.h Node.h testmain.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=A1.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

		rm -rf *.o core
%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

c:
	rm -rf *.o core
