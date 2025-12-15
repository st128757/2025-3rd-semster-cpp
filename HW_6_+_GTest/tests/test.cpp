#include "pch.h"
#include "Array.h"
#include "gtest/gtest.h"

// Тест 1: Конструктор по умолчанию создает нулевой массив
TEST(ArrayTest, DefaultConstructorCreatesZeroArray) {
    Array<int, 5> arr;

    // Создаем временный вывод для проверки
    testing::internal::CaptureStdout();
    arr.Show();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[0, 0, 0, 0, 0]");
}

// Тест 2: Конструктор с данными правильно инициализирует массив
TEST(ArrayTest, ConstructorWithDataInitializesCorrectly) {
    int data[] = { 1, 2, 3, 4, 5 };
    Array<int, 5> arr(data);

    testing::internal::CaptureStdout();
    arr.Show();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[1, 2, 3, 4, 5]");
}

// Тест 3: Конструктор с nullptr инициализирует нулями
TEST(ArrayTest, ConstructorWithNullptrInitializesWithZeros) {
    Array<int, 3> arr(nullptr);

    testing::internal::CaptureStdout();
    arr.Show();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[0, 0, 0]");
}

// Тест 4: Метод Minimum находит минимальный элемент (но есть баг!)
TEST(ArrayTest, MinimumFindsSmallestElement) {
    int data[] = { 10, 3, 45, -1, 20 };
    Array<int, 5> arr(data);
    Array<int, 5> dummy; // пустой массив для параметра

    // ВАЖНО: В вашем коде есть баг! min_val = min_val вместо min_val = array_[i]
    // Этот тест может упасть из-за бага
    try {
        int min_val = arr.Minimum(dummy);
        EXPECT_EQ(min_val, -1); // Ожидаем -1, но получим 10 из-за бага
    }
    catch (const std::runtime_error& e) {
        FAIL() << "Не должно быть исключения для непустого массива";
    }
}

// Тест 5: Minimum выбрасывает исключение для массива нулевого размера
TEST(ArrayTest, MinimumThrowsForZeroSizeArray) {
    // Создаем специализацию для размера 0
    Array<int, 0> arr;
    Array<int, 0> dummy;

    EXPECT_THROW({
        arr.Minimum(dummy);
        }, std::runtime_error);
}

// Тест 6: Работа с разными типами данных
TEST(ArrayTest, WorksWithDifferentDataTypes) {
    // Тест с double
    double double_data[] = { 3.14, 1.05, 2.71, 0.99 };
    Array<double, 4> double_arr(double_data);
    Array<double, 4> double_dummy;

    testing::internal::CaptureStdout();
    double_arr.Show();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[3.14, 1.05, 2.71, 0.99]");

    // Тест с char
    char char_data[] = { 'a', 'b', 'c' };
    Array<char, 3> char_arr(char_data);
    Array<char, 3> char_dummy;

    testing::internal::CaptureStdout();
    char_arr.Show();
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[a, b, c]");
}

// Тест 7: Метод Show корректно форматирует вывод (дополнительный тест)
TEST(ArrayTest, ShowFormatsOutputCorrectly) {
    int data[] = { 42 };
    Array<int, 1> single_element_arr(data);

    testing::internal::CaptureStdout();
    single_element_arr.Show();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[42]");

    int data2[] = { 1, 2 };
    Array<int, 2> two_element_arr(data2);

    testing::internal::CaptureStdout();
    two_element_arr.Show();
    output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[1, 2]");
}

// Основная функция для запуска тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}