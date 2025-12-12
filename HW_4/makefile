TARGET = main
SRCS = Source.cpp string.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = g++
CXXSTD = -std=c++17
CXXFLAGS_DEFAULT = -Wall -Wextra $(CXXSTD)

ifeq ($(CXXFLAGS),)
    CXXFLAGS := $(CXXFLAGS_DEFAULT)
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)