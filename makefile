CC=g++
SOURCES=main.cpp Physics.cpp DeltaVCalc.cpp TWRCalc.cpp ISPCalc.cpp TrueDVCalc.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=kspclicalc
BINDIR="/usr/bin"

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
	
install: all
	mkdir -p $(DESTDIR)$(BINDIR)
	cp $(CURDIR)/$(EXECUTABLE) $(DESTDIR)$(BINDIR)
