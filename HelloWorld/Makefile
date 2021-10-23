# Makefile
# , 2021-10-22 05:35
#
SHELL:=/usr/bin/env bash
PRG_SUFFIX_FLAG := 1
ifeq ($(origin CXX),default)
CXX := g++
endif
TERMUX := termux-elf-cleaner
LDFLAGS := 
CXXFLAGS_INC := -std=c++17
CXXFLAGS := -g -Wall  $(CXXFLAGS_INC)

PRG_SUFFIX=.out

SRCS := $(wildcard *.cpp)
PRGS := $(patsubst %.cpp,%,$(SRCS))
BINS := $(patsubst %,%$(PRG_SUFFIX),$(PRGS))
$(info $$BINS is [${BINS}])
## OBJS are automagically compiled by make.
## It's not quite magic.Relies on implicit 
## rule for .c files.
OBJS := $(patsubst %,%.o,$(PRGS))
DEPS := 

all: $(BINS)

.SECONDEXPANSION:
SRC = $(patsubst %$(PRG_SUFFIX),%.cpp,$@)
OBJ = $(patsubst %$(PRG_SUFFIX),%.o,$@)
COMPILE =	$(CXX) -o $(OBJ) -c $(SRC)
LINK =	$(CXX) $(OBJ) $(DEPS) $(LDFLAGS) -o $(BIN)
STRIP =	$(TERMUX) $(BIN) &> /dev/null || true

ifeq ($(PRG_SUFFIX_FLAG),0)
	BIN = $(patsubst %$(PRG_SUFFIX),%,$@)
else
	BIN = $@
endif
## Compile and link  the executable
## The rule below explicitly links the 
## .o files.
%$(PRG_SUFFIX) : $(OBJS)
	echo $@
	-$(LINK)
	-$(STRIP)

$(OBJS): $(SRCS)

$(SRCS):
	-$(COMPILE)

##
## $(OBJS) should be automagically removed right after linking.
##
veryclean:
ifeq ($(PRG_SUFFIX_FLAG),0)
	$(RM) $(PRGS) $(OBJS) || true
else
	$(RM) $(BINS) $(OBJS) || true
endif

rebuild: veryclean all

.PHONY: rebuild veryclean all
