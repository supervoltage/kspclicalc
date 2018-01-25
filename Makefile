CXX=g++
CXXFLAGS=-g -Wall --std=c++17
LDFLAGS=-g
SOURCES := $(shell find src/ -type f -name '*.cpp')
OBJECTS := $(SOURCES:.cpp=.o)
SDIR=src
EXECUTABLE=kspclicalc
DEPS := $(SOURCES:.cpp=.h)

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

%.cpp%.o: $(SOURCES) $(DEPS)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm $(OBJECTS)

cleanest:
	rm $(OBJECTS) $(EXECUTABLE)
