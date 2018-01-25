CC=g++
CFLAGS=-c -Wall --std=c++17
LDFLAGS=
SOURCES := $(shell find src/ -type f -name '*.cpp')
OBJECTS := $(SOURCES:.cpp=.o)
ODIR=obj
SDIR=src
EXECUTABLE=kspclicalc
DEPS := $(SOURCES:.cpp=.h)

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJECTS)
