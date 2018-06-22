CXX 		:= g++
TARGET 	:= avl

SRCEXT 	:= cpp
HDREXT 	:= h
SRCDIR 	:= ./src
HDRDIR 	:= ./include
DOXDIR 	:= ./doxy

SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
HEADERS := $(shell find $(HDRDIR) -type f -name "*.$(HDREXT)")

CFLAGS 	:= -g -Wall -std=c++11 -I$(HDRDIR)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) -o $@ $(SOURCES) $(CFLAGS)

run:
	./$(TARGET)

all: clean $(TARGET) run

doxygen:
	doxygen $(DOXDIR)/doxyfile

clean:
	@echo "Clenaing..."
	$(RM) -r $(TARGET) $(DOXDIR)/html

.PHONY: clean
