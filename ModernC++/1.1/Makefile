SHELL := /bin/bash
C = gcc
CXX = clang++
TERMUX_CLEANER = termux-elf-cleaner
SOURCE_C = foo.c
OBJECTS_C = foo.o
SOURCE_CXX = main.cpp
TARGET = a.out
LDFLAGS_COMMON = -std=c++2a
all:
	$(C) -c $(SOURCE_C)
	$(CXX) $(SOURCE_CXX) $(OBJECTS_C) $(LDFLAGS_COMMON) -o $(TARGET)
	$(TERMUX_CLEANER) $(TARGET) &> /dev/null
clean:
	rm -rf *.o $(TARGET)
