CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I.
LDFLAGS =

.PHONY: all clean test lint format

all: bank_app unit_tests

bank_app: main.cpp Bank.cpp Bank.h
	$(CXX) $(CXXFLAGS) $^ -o $@

unit_tests: test.cpp Bank.cpp Bank.h
	$(CXX) $(CXXFLAGS) test.cpp Bank.cpp -o $@ -pthread -lgtest -lgtest_main

test: unit_tests
	./unit_tests

clean:
	rm -f bank_app unit_tests

# Линтер
# Установи cpplint через pip: pip install cpplint
lint:
	cpplint --root=. --filter=-legal/copyright,-build/include_subdir Bank.h Bank.cpp test.cpp main.cpp

# Форматирование
# Установи clang-format: sudo apt install clang-format
format:
	clang-format -i Bank.h Bank.cpp test.cpp main.cpp
