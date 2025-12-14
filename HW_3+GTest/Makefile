# Простой Makefile для проекта Banking System
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Основная цель
all: main

# Сборка основной программы
main: Source.cpp Bank.cpp Bank.h
	$(CXX) $(CXXFLAGS) Source.cpp Bank.cpp -o main

# Сборка тестов
tests: SimpleTests.cpp Bank.cpp Bank.h
	$(CXX) $(CXXFLAGS) SimpleTests.cpp Bank.cpp -o tests

# Debug сборка
debug: CXXFLAGS += -g -O0 -DDEBUG
debug: main

# Release сборка
release: CXXFLAGS += -O2 -DNDEBUG
release: main

# Сборка с санитайзерами
sanitize: CXXFLAGS += -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer
sanitize: main

# Очистка
clean:
	rm -f main tests

# Запуск
run: main
	./main

# Тестирование
test: tests
	./tests

.PHONY: all clean run test debug release sanitize
