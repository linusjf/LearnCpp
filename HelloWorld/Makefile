#
# Makefile
# , 2021-10-22 05:35
#
SRC=$(wildcard *.cpp)
OBJ=$(wildcard *.o)
DST=$(patsubst %.cpp, %, $(SRC))
OBJS=$(patsubst %.o, %, $(OBJ))

%: %.cpp
	g++ -o $@ -c $@.cpp
# termux-elf-cleaner $@ > /dev/null

$(DST): $(SRC)

all: $(DST)

clean:
	rm *.o HelloWorld PrintNums

.PHONY: clean
