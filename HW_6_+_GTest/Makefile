# Простой Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
LDFLAGS = -lgtest -lgtest_main -pthread

all: program.exe tests.exe

# Основная программа
program.exe: src/main.cpp src/Array.h
	$(CXX) $(CXXFLAGS) src/main.cpp -o program.exe

# Тесты
tests.exe: tests/test.cpp src/Array.h
	$(CXX) $(CXXFLAGS) tests/test.cpp $(LDFLAGS) -o tests.exe

# Запуск
run: program.exe
	./program.exe

test: tests.exe
	./tests.exe

clean:
	rm -f *.exe

# Для Windows
ifeq ($(OS),Windows_NT)
clean:
	del /Q *.exe 2>nul || true
endif

.PHONY: all run test clean