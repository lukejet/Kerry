
GCC:=g++
CFLAGS:= -g -O2 -Wall 

SOURCES := $(wildcard *.c *.cpp *.cc)
TARGETS  := $(patsubst %.c,  %, $(SOURCES) )
TARGETS  := $(patsubst %.cpp,%, $(TARGETS) )
TARGETS  := $(patsubst %.S,  %, $(TARGETS) )


.PHONY : test
test: 
	@echo $(TARGETS)

all: $(TARGETS) 

# Common commands
BUILD_ECHO = echo "\n  [build]  $@:"

define build_bin
    @$(BUILD_ECHO)
    $(GCC)  $< -o $@ $(CFLAGS)
    @echo "\n---- Compiled $@ ----\n"
endef
	
%: %.cpp
	@$(BUILD_ECHO)
	g++ $< -o $@ $(CFLAGS) -std=c++11
	@echo "\n---- Compiled $@ ----\n"

	
%: %.c
	@$(BUILD_ECHO)
	gcc  $< -o $@ $(CFLAGS)
	@echo "\n---- Compiled $@ ----\n"

.PHONY: clean
clean:
	rm -rf $(TARGETS)
	
