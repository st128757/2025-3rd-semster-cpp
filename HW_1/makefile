CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
LDFLAGS = -lm

TARGET = main
SRC = Source.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
$(CXX) $(LDFLAGS) $(OBJ) -o $@

%.o: %.cpp
$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
rm -f $(TARGET) $(OBJ)
