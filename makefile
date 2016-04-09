#It is my first makefile, Good luck!
CC = g++
CFLAGS = -c -Wall
LDFLAGS = 
SOURCES = Hesitate.cpp
OBJECTS = $(SOURCES:.cpp = .o)
EXECUTABLE = Hesitate

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@