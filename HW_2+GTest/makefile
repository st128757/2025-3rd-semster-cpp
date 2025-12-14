CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g -I.
LDFLAGS = -lgtest -lgtest_main -lpthread

MAIN_SRCS = TextEditor.cpp main.cpp pch.cpp
TEST_SRCS = TextEditor.cpp test.cpp pch.cpp

MAIN_TARGET = main
TEST_TARGET = test_runner

.PHONY: all clean test sanitize

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(MAIN_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_TARGET): $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

sanitize: CXXFLAGS += -fsanitize=address,undefined -fno-omit-frame-pointer
sanitize: LDFLAGS += -fsanitize=address,undefined
sanitize: clean $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(MAIN_TARGET) $(TEST_TARGET) *.o

format:
	clang-format -i -style=Google *.cpp *.h
