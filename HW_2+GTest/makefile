CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -g
LDFLAGS = 

# Директории
SRC_DIR = .
TEST_DIR = .
BUILD_DIR = build

# Исходные файлы
SRCS = TextEditor.cpp
TEST_SRCS = test.cpp

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
TEST_OBJS = $(TEST_SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Цели
TARGET = $(BUILD_DIR)/main
TEST_TARGET = $(BUILD_DIR)/test_runner

# Google Test (если установлен через vcpkg или system)
GTEST_DIR = /usr/include/gtest
GTEST_LIBS = -lgtest -lgtest_main -lpthread

# Основные цели
.PHONY: all clean run test format lint sanitize

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(BUILD_DIR)/main.o $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/main.o: main.cpp $(SRCS:.cpp=.h)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIBS) $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp %.h
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/test.o: test.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I. -c $< -o $@

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

format:
	clang-format -i -style=Google *.cpp *.h

check-format:
	clang-format --dry-run -Werror -style=Google *.cpp *.h

lint:
	cppcheck --enable=all --inconclusive --suppress=missingIncludeSystem *.cpp *.h

sanitize: CXXFLAGS += -fsanitize=address,undefined -fno-omit-frame-pointer
sanitize: LDFLAGS += -fsanitize=address,undefined
sanitize: clean all

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

# Справка
help:
	@echo "Доступные цели:"
	@echo "  all       - собрать все цели (по умолчанию)"
	@echo "  run       - собрать и запустить основную программу"
	@echo "  test      - собрать и запустить тесты"
	@echo "  format    - отформатировать код"
	@echo "  lint      - проверить код статическим анализатором"
	@echo "  sanitize  - собрать с санитайзерами Address и Undefined"
	@echo "  valgrind  - проверить утечки памяти"
	@echo "  clean     - удалить скомпилированные файлы"

$(shell mkdir -p $(BUILD_DIR))