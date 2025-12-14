#include "pch.h"
#include "gtest/gtest.h"
#include "TextEditor.h" 
#include <string>
#include <utility>

struct SimpleTextEditorTest : public ::testing::Test {
    TextEditor editor;
};

// -----------------------------------------------------------
// 1. Тест на базовый ввод и проверку позиции курсора
// -----------------------------------------------------------
TEST_F(SimpleTextEditorTest, BasicInputAndCursorPosition) {
    // 1. Arrange
    // Редактор пуст

    // 2. Act
    editor.AddText("Hello");

    // 3. Assert
    ASSERT_EQ("Hello", editor.GetFullText());
    ASSERT_EQ(std::make_pair(0, 5), editor.GetCursorPosition());
}

// -----------------------------------------------------------
// 2. Тест на слияние строк при удалении (Backspace) в начале второй строки
// -----------------------------------------------------------
TEST_F(SimpleTextEditorTest, DeleteAtLineStart) {
    // 1. Arrange
    editor.AddText("First");
    editor.AddNewLine();
    editor.AddText("Second");

    // Перемещаем курсор в начало второй строки
    editor.CursorLeft(6);
    ASSERT_EQ(std::make_pair(1, 0), editor.GetCursorPosition());

    int first_line_len = 5; // Длина "First"

    // 2. Act
    editor.DeleteText(1); // Удаление '\n'

    // 3. Assert
    ASSERT_EQ("FirstSecond", editor.GetFullText());
    // Курсор должен быть в точке слияния
    ASSERT_EQ(std::make_pair(0, first_line_len), editor.GetCursorPosition());
}

// -----------------------------------------------------------
// 3. Тест на создание новой строки (Enter)
// -----------------------------------------------------------
TEST_F(SimpleTextEditorTest, SplitLineWithEnter) {
    // 1. Arrange
    editor.AddText("Line one and two.");
    // Перемещаем курсор после "Line one"
    editor.CursorLeft(9);
    ASSERT_EQ(std::make_pair(0, 8), editor.GetCursorPosition());

    // 2. Act
    editor.AddNewLine();

    // 3. Assert
    ASSERT_EQ("Line one\n and two.", editor.GetFullText());
    // Курсор должен быть в начале новой строки
    ASSERT_EQ(std::make_pair(1, 0), editor.GetCursorPosition());
}

// -----------------------------------------------------------
// 4. Тест на удаление символа и слияние строк (общий тест)
// -----------------------------------------------------------
TEST_F(SimpleTextEditorTest, DeleteTextAndMergeLines) {
    // 1. Arrange
    editor.AddText("First line");
    editor.AddNewLine();
    editor.AddText("Second line");
    editor.CursorLeft(11); // Курсор в начале второй строки

    // 2. Act
    editor.DeleteText(1);

    // 3. Assert
    ASSERT_EQ("First lineSecond line", editor.GetFullText());
    ASSERT_EQ(std::make_pair(0, 10), editor.GetCursorPosition());
}

// -----------------------------------------------------------
// 5. Тест на перемещение курсора вверх/вниз и ограничение столбца
// -----------------------------------------------------------
TEST_F(SimpleTextEditorTest, CursorVerticalMovementAndClamping) {
    // 1. Arrange
    editor.AddText("Long Line"); // 9
    editor.AddNewLine();
    editor.AddText("Short"); // 5
    editor.AddNewLine();
    editor.AddText("Another Long Line"); // 17

    editor.CursorUp(2); // Курсор на (0, 9)

    // 2. Act
    editor.CursorDown(1); // Переход на "Short"

    // 3. Assert
    // Курсор должен быть на (1, min(9, 5)) = (1, 5)
    ASSERT_EQ(std::make_pair(1, 5), editor.GetCursorPosition());
}

// -----------------------------------------------------------
// 6. Тест на крайние случаи: границы перемещения и удаления
// -----------------------------------------------------------
TEST_F(SimpleTextEditorTest, EdgeCases_BoundsAndEmptyDelete) {
    // 1. Arrange
    editor.AddText("Data");

    // 2. Act
    // Попытка движения за границы
    editor.CursorRight(5);
    editor.CursorLeft(10); // Курсор (0, 0)
    editor.DeleteText(1); // Удаление в начале строки

    // 3. Assert
    ASSERT_EQ(std::make_pair(0, 0), editor.GetCursorPosition());
    ASSERT_EQ("Data", editor.GetFullText()); // Текст не должен измениться
}