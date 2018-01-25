CC=g++
CFLAGS=-c -Wall --std=c++17 -g
LDFLAGS= -g
SOURCES := $(shell find src/ -type f -name '*.cpp')
OBJECTS := $(SOURCES:.cpp=.o)
SDIR=src
EXECUTABLE=kspclicalc
DEPS := $(SOURCES:.cpp=.h)

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJECTS)
