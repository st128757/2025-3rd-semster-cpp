# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread
SANITIZER_FLAGS = -fsanitize=address -fsanitize=undefined

# Targets
TARGET = main
TEST_TARGET = test_runner

# Source files
MAIN_SRC = main.cpp TextEditor.cpp pch.cpp
TEST_SRC = test.cpp TextEditor.cpp pch.cpp
ALL_SRC = $(MAIN_SRC) $(TEST_SRC)

# Object files
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Main program
$(TARGET): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test runner
$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

# Test target (alias)
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Build with sanitizers
sanitize: CXXFLAGS += $(SANITIZER_FLAGS)
sanitize: $(TEST_TARGET)
	./$(TEST_TARGET)

# Pattern rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o

# Format code with clang-format
format:
	find . -name '*.cpp' -o -name '*.h' | xargs clang-format -i -style=Google

# Phony targets
.PHONY: all test sanitize clean format
