# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -Isrc
LDFLAGS = -lgtest -lgtest_main -pthread

# Пути
SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

# Файлы исходного кода
SRCS = $(SRC_DIR)/TextEditor.cpp $(SRC_DIR)/pch.cpp
MAIN_SRC = $(SRC_DIR)/main.cpp
TEST_SRC = $(TEST_DIR)/test.cpp

# Цели
.PHONY: all build test clean sanitize format check-style lint run help

all: build

help:
	@echo "Доступные команды:"
	@echo "  make build        - Собрать текстовый редактор"
	@echo "  make test         - Собрать и запустить тесты"
	@echo "  make sanitize     - Запустить тесты с санитайзерами"
	@echo "  make check-style  - Проверить Google Code Style"
	@echo "  make lint         - Запустить статический анализ"
	@echo "  make format       - Форматировать код"
	@echo "  make run          - Запустить редактор"
	@echo "  make clean        - Очистить бинарные файлы"

# Основная программа
build: $(BIN_DIR)/text_editor

$(BIN_DIR)/text_editor: $(MAIN_SRC) $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Тесты
test: $(BIN_DIR)/tests
	@echo "Запуск тестов..."
	./$(BIN_DIR)/tests

$(BIN_DIR)/tests: $(TEST_SRC) $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# Тесты с санитайзерами
sanitize: $(TEST_SRC) $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined -fno-omit-frame-pointer $^ $(LDFLAGS) -o $(BIN_DIR)/tests_sanitize
	@echo "Запуск тестов с санитайзерами..."
	./$(BIN_DIR)/tests_sanitize

# Проверка стиля кода
check-style:
	@echo "Проверка Google Code Style..."
	@find $(SRC_DIR) $(TEST_DIR) -name "*.cpp" -o -name "*.h" | xargs clang-format --dry-run --Werror

# Форматирование кода
format:
	@echo "Форматирование кода..."
	@find $(SRC_DIR) $(TEST_DIR) -name "*.cpp" -o -name "*.h" | xargs clang-format -i

# Статический анализ
lint:
	@echo "Статический анализ кода..."
	@find $(SRC_DIR) $(TEST_DIR) -name "*.cpp" -o -name "*.h" | xargs -I {} clang-tidy {} -checks='*' --warnings-as-errors='*' --

# Запуск программы
run: build
	./$(BIN_DIR)/text_editor

# Очистка
clean:
	rm -rf $(BIN_DIR)/
	find . -name "*.o" -delete