# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I./src
LDFLAGS = -lgtest -lgtest_main -pthread

# Пути
SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

# Файлы
SRCS = $(SRC_DIR)/Bank.cpp $(SRC_DIR)/pch.cpp
MAIN_SRC = $(SRC_DIR)/main.cpp
TEST_SRC = $(TEST_DIR)/test.cpp

# Цели
.PHONY: all build test clean sanitize format check-style lint help

all: build

help:
	@echo "Доступные команды:"
	@echo "  make build    - Собрать основную программу"
	@echo "  make test     - Собрать и запустить тесты"
	@echo "  make sanitize - Запустить тесты с санитайзерами"
	@echo "  make format   - Форматировать код"
	@echo "  make check-style - Проверить стиль кода"
	@echo "  make lint     - Запустить статический анализ"
	@echo "  make clean    - Очистить бинарные файлы"
	@echo "  make all      - Собрать всё"

# Основная программа
build: $(BIN_DIR)/main

$(BIN_DIR)/main: $(MAIN_SRC) $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Тесты
test: $(BIN_DIR)/tests
	@echo "Запуск тестов..."
	./$(BIN_DIR)/tests

$(BIN_DIR)/tests: $(TEST_SRC) $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# Тесты с санитайзерами (Address + Undefined Behavior)
sanitize: $(TEST_SRC) $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined -fno-omit-frame-pointer $^ $(LDFLAGS) -o $(BIN_DIR)/tests_sanitize
	@echo "Запуск тестов с санитайзерами..."
	./$(BIN_DIR)/tests_sanitize

# Форматирование кода (clang-format)
format:
	@echo "Форматирование кода..."
	@find $(SRC_DIR) $(TEST_DIR) -name "*.cpp" -o -name "*.h" | xargs clang-format -i

# Проверка стиля кода (Google Code Style)
check-style:
	@echo "Проверка Google Code Style..."
	@if ! command -v clang-format >/dev/null 2>&1; then \
		echo "Установите clang-format: sudo apt-get install clang-format"; \
		exit 1; \
	fi
	@find $(SRC_DIR) $(TEST_DIR) -name "*.cpp" -o -name "*.h" | xargs clang-format --dry-run --Werror

# Статический анализ (clang-tidy)
lint:
	@echo "Статический анализ кода..."
	@if ! command -v clang-tidy >/dev/null 2>&1; then \
		echo "Установите clang-tidy: sudo apt-get install clang-tidy"; \
		exit 1; \
	fi
	@find $(SRC_DIR) $(TEST_DIR) -name "*.cpp" -o -name "*.h" | xargs -I {} clang-tidy {} -checks='*' --warnings-as-errors='*' --

# Очистка
clean:
	@echo "Очистка..."
	rm -rf $(BIN_DIR)/
	find . -name "*.o" -delete

# Запуск программы
run: build
	./$(BIN_DIR)/main
