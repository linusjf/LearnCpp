# Makefile
# 2021-10-22 05:35
#
SHELL:=/usr/bin/env bash
TERMUX := termux-elf-cleaner
PRG_SUFFIX_FLAG := 1
CXX := g++
LDFLAGS := 
CXXFLAGS_INC := -std=c++17
CXXFLAGS := -g -Wall $(CXXFLAGS_INC)
AWK := awk
GREP := grep
SORT := sort
PR := pr

PRG_SUFFIX = .out

SRCS := $(wildcard *.cpp)
PRGS := $(patsubst %.cpp,%,$(SRCS))
BINS := $(patsubst %,%$(PRG_SUFFIX),$(PRGS))
#$(info $$BINS is [${BINS}])
OBJS := $(patsubst %,%.o,$(PRGS))
DEPS := 

define help-script
	@$(MAKE) --print-data-base --question no-such-target | \
		$(GREP) -v -e '^no-such-target' -e '^makefile' | \
		$(AWK) '/^[^.%][-A-Za-z0-9_]*:/ { print substr($$1, 1, length($$1)-1) }' | \
		$(SORT) | \
	  $(PR) --omit-pagination --width=80 --columns=4
endef

# help - The default goal
help:
	${help-script}

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
%$(PRG_SUFFIX) : $(OBJS)
	@echo $@
	-$(LINK)
	-$(STRIP)

$(OBJS): %.o:%.cpp

veryclean:
ifeq ($(PRG_SUFFIX_FLAG),0)
	$(RM) $(PRGS) $(OBJS) || true
else
	$(RM) $(BINS) $(OBJS) || true
endif

rebuild: veryclean all

no-such-target: ;

.PHONY: rebuild veryclean help no-such-target
