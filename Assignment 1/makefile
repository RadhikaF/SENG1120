CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=LinkedListDemo.cpp node.cpp LinkedList.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=demo

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core