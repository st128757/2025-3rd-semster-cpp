# ====================================================================
# Makefile для сборки и тестирования проекта Bank
# Предполагается, что установлены g++, gtest, cpplint, clang-format
# ====================================================================

# Переменные
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I.
LDFLAGS = -pthread -lgtest -lgtest_main # Флаги для Google Test

# Исходники
BANK_SOURCES = Bank.cpp
TEST_SOURCE = test.cpp
MAIN_SOURCE = main.cpp
HEADERS = Bank.h pch.h

# Имена выходных файлов
TEST_EXEC = unit_tests
APP_EXEC = bank_app

.PHONY: all clean test lint format asan

# Основная цель: сборка всего
all: $(APP_EXEC) $(TEST_EXEC)

# Сборка основной программы
$(APP_EXEC): $(MAIN_SOURCE) $(BANK_SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(MAIN_SOURCE) $(BANK_SOURCES) -o $@

# Сборка тестов
$(TEST_EXEC): $(TEST_SOURCE) $(BANK_SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCE) $(BANK_SOURCES) -o $@ $(LDFLAGS)

# Сборка тестов с Address Sanitizer (ASan)
# Флаги -fsanitize=address,undefined включают санитайзеры
asan:
	$(CXX) $(CXXFLAGS) $(TEST_SOURCE) $(BANK_SOURCES) -o $(TEST_EXEC)_asan $(LDFLAGS) -fsanitize=address,undefined -fno-omit-frame-pointer

# Запуск тестов
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Запуск тестов с санитайзерами
test_asan: asan
	./$(TEST_EXEC)_asan

# Линтер (проверка Google Code Style)
# Требует установки cpplint: pip install cpplint
lint:
	@echo "--- Running cpplint for Google Code Style Check ---"
	cpplint --root=. --filter=-legal/copyright,-build/include_subdir $(HEADERS) $(BANK_SOURCES) $(TEST_SOURCE) $(MAIN_SOURCE)

# Форматирование (для автоматического исправления стиля)
# Требует установки clang-format
format:
	@echo "--- Running clang-format for auto-formatting ---"
	clang-format -i $(HEADERS) $(BANK_SOURCES) $(TEST_SOURCE) $(MAIN_SOURCE)

# Очистка
clean:
	rm -f $(TEST_EXEC) $(TEST_EXEC)_asan $(APP_EXEC)
