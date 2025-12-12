TARGET = main

SOURCE = Source.cpp

CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17 -g

LDFLAGS =

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
	

sanitizer_build: clean
	$(CXX) -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer $(SOURCE) -o $(TARGET) $(LDFLAGS)

.PHONY: all clean sanitizer_build