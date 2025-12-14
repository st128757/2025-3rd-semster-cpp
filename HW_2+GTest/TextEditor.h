#pragma once

#include <algorithm>
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>


class TextEditor {
private:
	std::vector<std::string> lines_;
	int cursor_row_;
	int cursor_col_;

	std::string GetTextBeforeCursor();

	void RefreshDisplay();

public:
	TextEditor();

	void HandleKeyPress(char key);

	void AddText(std::string text);
	int DeleteText(int k);
	void AddNewLine();

	std::string CursorLeft(int k);
	std::string CursorRight(int k);
	std::string CursorUp(int k);
	std::string CursorDown(int k);

	void RunInteractive();
	void PrintText();

	std::string GetFullText();
	std::pair<int, int> GetCursorPosition();
};