SHELL := /bin/bash
CXX = g++
TERMUX_CLEANER = termux-elf-cleaner
SOURCE_CXX = $(SOURCE).cpp
override TARGET = a.out
LDFLAGS_COMMON = -std=c++2a
WFLAGS= -w
all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS_COMMON) $(WFLAGS) -o $(TARGET)
	$(TERMUX_CLEANER) $(TARGET) &> /dev/null
	./$(TARGET)
clean:
	rm -rf $(TARGET)
