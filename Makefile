CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -Iinclude
LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = BABA_IS_YOU

SRCDIR = src
BUILDDIR = build

SOURCES = $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

run: $(TARGET)
	./$(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

build/keyboardListener.o: src/cpp/keyboardListener.cpp src/hpp/keyboardListener.hpp | build
	$(CCO) -o $@

clean:
	rm -rf $(BUILDDIR) $(TARGET)