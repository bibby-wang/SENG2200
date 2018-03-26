CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Polygon.cpp Point.cpp MyPolygons.h Node.h main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=A1.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@


%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

c:
	rm -rf *.o core
