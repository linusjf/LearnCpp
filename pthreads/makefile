CFLAGS = -DTRACEMSG -pthread -std=c++11
CC     = g++
 
all:    pipe bpipe
 
pipe:   pipe.cpp Channel.hpp
	$(CC) $(CFLAGS) pipe.cpp -o pipe.out
	termux-elf-cleaner pipe.out > /dev/null
 
bpipe:  bpipe.cpp BChannel.hpp
	$(CC) $(CFLAGS) bpipe.cpp -o bpipe.out
	termux-elf-cleaner bpipe.out > /dev/null
 
clean:
	rm -f pipe.out bpipe.out a.out *~
