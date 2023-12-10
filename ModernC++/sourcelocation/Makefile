SHELL := /bin/bash
CXX = clang++
TERMUX_CLEANER = termux-elf-cleaner
SOURCE_CXX = main.cpp
TARGET = a.out
LDFLAGS_COMMON = -std=c++2a
all:
  $(CXX) $(SOURCE_CXX) $(OBJECTS_C) $(LDFLAGS_COMMON) -o $(TARGET)
  $(TERMUX_CLEANER) $(TARGET) &> /dev/null || (sh -c 'exit 0')
clean:
  rm -rf *.o $(TARGET)
