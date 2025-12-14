# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++11 -Wall -Wextra

# Цель по умолчанию - собираем основную программу
all: main

# Сборка основной программы
main: Bank.cpp Source.cpp Bank.h
	$(CXX) $(CXXFLAGS) Bank.cpp Source.cpp -o main

# Сборка тестов
tests: Bank.cpp SimpleTests.cpp Bank.h
	$(CXX) $(CXXFLAGS) Bank.cpp SimpleTests.cpp -o tests

# Сборка с санитайзерами (для workflow)
sanitize: Bank.cpp Source.cpp Bank.h
	$(CXX) $(CXXFLAGS) -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer Bank.cpp Source.cpp -o main

# Запуск программы
run: main
	./main

# Запуск тестов
test: tests
	./tests

# Очистка
clean:
	rm -f main tests *.o

# Форматирование кода
format:
	clang-format -i -style=Google *.cpp *.h

# Помощь
help:
	@echo "Доступные команды:"
	@echo "  make        - Собрать основную программу"
	@echo "  make run    - Собрать и запустить программу"
	@echo "  make tests  - Собрать тесты"
	@echo "  make test   - Собрать и запустить тесты"
	@echo "  make clean  - Удалить скомпилированные файлы"
	@echo "  make format - Отформатировать код"
	@echo "  make help   - Показать эту справку"

.PHONY: all run test clean format help