SHELL := /bin/bash
CXX = g++
TERMUX_CLEANER = termux-elf-cleaner
SOURCE_CXX = $(SOURCE).cpp
override TARGET = $(SOURCE).out
LDFLAGS_COMMON = -std=c++2a
all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS_COMMON) -o $(TARGET)
	$(TERMUX_CLEANER) $(TARGET) &> /dev/null
	./$(TARGET)
clean:
	rm -rf $(TARGET)
