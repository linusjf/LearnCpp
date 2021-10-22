#
# Makefile
# , 2021-10-22 05:35
#
SRC=$(wildcard *.cpp)
DST=$(patsubst %.cpp, %, $(SRC))

%: %.cpp
	g++ -o $@ $@.cpp
	termux-elf-cleaner $@ > /dev/null

$(DST): $(SRC)

all: $(DST)
