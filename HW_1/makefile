CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
LDFLAGS = -lm

TARGET = main
SRC = Source.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
