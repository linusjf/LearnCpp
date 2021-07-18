SHELL := /usr/bin/env bash
CXX = g++
TERMUX_CLEANER = termux-elf-cleaner
SOURCE_CXX = $(BASE).cpp
TARGET = a.out
LDFLAGS_COMMON = -std=c++20 -g
all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS_COMMON) -o $(TARGET)
	$(TERMUX_CLEANER) $(TARGET) &> /dev/null
run:
	./$(TARGET)
runswitch:
	./$(TARGET) a
	./$(TARGET) b
	./$(TARGET) c
runset:
	echo "a a a b c foo bar foobar foo bar bar" | ./$(TARGET)
runmultiset:
	echo "a a a b c foo bar foobar foo bar bar" | ./$(TARGET)
runrpn:
	echo "3 1 2 + * 2 /" | ./$(TARGET)
runadapter:
	echo "1 2 3 4 5" | ./$(TARGET)
runconjunct:
	echo "ac cb ab axxxb" | ./$(TARGET)
runwc:
	cat loremipsum.txt | ./$(TARGET)
runsentinel:
	./$(TARGET) "abcdefghijklmnopqrstuvwxyz"
runtransformif:
	echo "1 2 3 4 5 6 7 8 9 0" | ./$(TARGET) 
runpermute:
	echo "a b c d" | ./$(TARGET) 
rundict:
	cat dict2.txt | ./$(TARGET) 
clean:
	rm -f ./$(TARGET)
dumpast:
	clang -Xclang -ast-dump -fsyntax-only $(BASE).cpp
dumprecord:
	clang -E $(BASE).cpp > $(BASE)_pp.cpp
	clang -cc1 -emit-llvm -fdump-record-layouts-simple $(BASE)_pp.cpp
