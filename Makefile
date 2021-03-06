CXX 		:= g++
TARGET 	:= avl

SRCEXT 	:= cpp
HDREXT 	:= h
SRCDIR 	:= ./src
HDRDIR 	:= ./include

SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
HEADERS := $(shell find $(HDRDIR) -type f -name "*.$(HDREXT)")

CFLAGS 	:= -g -Wall -std=c++11 -I$(HDRDIR)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) -o $@ $(SOURCES) $(CFLAGS)

run:
	./$(TARGET)

all: clean $(TARGET) run

clean:
	@echo "Clenaing..."
	$(RM) $(TARGET)

.PHONY: clean
