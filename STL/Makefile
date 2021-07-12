SHELL := /usr/bin/env bash
CXX = g++
TERMUX_CLEANER = termux-elf-cleaner
SOURCE_CXX = $(BASE).cpp
TARGET = a.out
LDFLAGS_COMMON = -std=c++2a -stdlib=libc++
all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS_COMMON) -o $(TARGET)
	$(TERMUX_CLEANER) $(TARGET) &> /dev/null
run:
	./$(TARGET)
runswitch:
	./$(TARGET) a
	./$(TARGET) b
	./$(TARGET) c
clean:
	rm -rf *.o $(TARGET)
