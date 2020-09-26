CC=g++

SOURCES= main.cpp ./modules/Fraction/Fraction.cpp

EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) -o $@
