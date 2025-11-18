CC = g++
CFLAGS = -Wall -Wextra --std=c++11 -Iinclude
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
CCO = $(CC) $(CFLAGS) -c $<
OBJECTS = build/main.o build/keyboardListener.o
TARGET = BABA_IS_YOU

all: $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LFLAGS)

run: $(TARGET)
	./$(TARGET)

build:
	mkdir -p build

build/main.o: src/main.cpp | build
	$(CCO) -o $@ 

build/keyboardListener.o: src/cpp/keyboardListener.cpp src/hpp/keyboardListener.hpp | build
	$(CCO) -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean
