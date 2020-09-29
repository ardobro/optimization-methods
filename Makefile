CC=g++

CFLAGS=-c -Wall

LDFLAGS=

SOURCES= main.cpp ./modules/Fraction/Fraction.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
