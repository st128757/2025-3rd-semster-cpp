TARGET = main
SRC = Source.cpp
CXX = g++
CXXSTD = -std=c++17
CXXFLAGS_DEFAULT = -Wall -Wextra $(CXXSTD)

ifeq ($(CXXFLAGS),)
    CXXFLAGS := $(CXXFLAGS_DEFAULT)
endif


.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGET)