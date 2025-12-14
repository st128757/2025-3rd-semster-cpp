CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2
SOURCES := Source.cpp
TARGET := main
OBJECTS := $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean run