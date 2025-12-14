#include "TextEditor.h"

#include "pch.h"

TextEditor::TextEditor() : lines_{""}, cursor_row_(0), cursor_col_(0) {}

void TextEditor::HandleKeyPress(char key) {
  switch (key) {
    case 8:
      DeleteText(1);
      break;
    case 13:
      AddNewLine();
      break;
    case 77:
      CursorRight(1);
      break;
    case 75:
      CursorLeft(1);
      break;
    case 72:
      CursorUp(1);
      break;
    case 80:
      CursorDown(1);
      break;
    default:
      if (key >= 32 && key <= 126) {
        AddText(std::string(1, key));
      }
      break;
  }
}

void TextEditor::AddText(std::string text) {
  std::string& current_line = lines_[cursor_row_];

  if (cursor_col_ < current_line.length()) {
    std::string prefix = current_line.substr(0, cursor_col_);
    std::string suffix = current_line.substr(cursor_col_);
    current_line = prefix + text + suffix;
  } else {
    current_line += text;
  }

  cursor_col_ += text.length();
  RefreshDisplay();
}

int TextEditor::DeleteText(int k) {
  int deleted = 0;

  for (int i = 0; i < k; i++) {
    if (cursor_col_ > 0) {
      std::string& current_line = lines_[cursor_row_];
      current_line.erase(cursor_col_ - 1, 1);
      cursor_col_--;
      deleted++;
    } else if (cursor_row_ > 0) {
      std::string& prev_line = lines_[cursor_row_ - 1];
      std::string& current_line = lines_[cursor_row_];

      cursor_col_ = prev_line.length();
      prev_line += current_line;
      lines_.erase(lines_.begin() + cursor_row_);
      cursor_row_--;
      deleted++;
    }
  }

  RefreshDisplay();
  return deleted;
}

std::string TextEditor::CursorLeft(int k) {
  for (int i = 0; i < k; i++) {
    if (cursor_col_ > 0) {
      cursor_col_--;
    } else if (cursor_row_ > 0) {
      cursor_row_--;
      cursor_col_ = lines_[cursor_row_].length();
    }
  }
  RefreshDisplay();
  return GetTextBeforeCursor();
}

std::string TextEditor::CursorRight(int k) {
  for (int i = 0; i < k; i++) {
    if (cursor_col_ < lines_[cursor_row_].length()) {
      cursor_col_++;
    } else if (cursor_row_ < lines_.size() - 1) {
      cursor_row_++;
      cursor_col_ = 0;
    }
  }
  RefreshDisplay();
  return GetTextBeforeCursor();
}

std::string TextEditor::CursorUp(int k) {
  for (int i = 0; i < k; i++) {
    if (cursor_row_ > 0) {
      cursor_row_--;
      cursor_col_ =
          std::min(cursor_col_, static_cast<int>(lines_[cursor_row_].length()));
    }
  }
  RefreshDisplay();
  return GetTextBeforeCursor();
}

std::string TextEditor::CursorDown(int k) {
  for (int i = 0; i < k; i++) {
    if (cursor_row_ < lines_.size() - 1) {
      cursor_row_++;
      cursor_col_ =
          std::min(cursor_col_, static_cast<int>(lines_[cursor_row_].length()));
    }
  }
  RefreshDisplay();
  return GetTextBeforeCursor();
}

void TextEditor::AddNewLine() {
  std::string& current_line = lines_[cursor_row_];

  if (cursor_col_ < current_line.length()) {
    std::string new_line = current_line.substr(cursor_col_);
    current_line.resize(cursor_col_);
    lines_.insert(lines_.begin() + cursor_row_ + 1, new_line);
  } else {
    lines_.insert(lines_.begin() + cursor_row_ + 1, "");
  }

  cursor_row_++;
  cursor_col_ = 0;
  RefreshDisplay();
}

std::string TextEditor::GetTextBeforeCursor() {
  std::string& current_line = lines_[cursor_row_];
  int start_pos = std::max(0, cursor_col_ - 10);
  return current_line.substr(start_pos, cursor_col_ - start_pos);
}

void TextEditor::RefreshDisplay() {
  system("cls");

  std::cout << "=== Text editor ===" << std::endl;
  std::cout << "Enter - new line, Esc - exit" << std::endl;
  std::cout << "==========================" << std::endl << std::endl;

  for (int i = 0; i < lines_.size(); i++) {
    std::cout << (i + 1) << ": ";

    if (i == cursor_row_) {
      std::string line = lines_[i];

      std::cout << line.substr(0, cursor_col_);

      std::cout << "|";

      if (cursor_col_ < line.length()) {
        std::cout << line.substr(cursor_col_);
      }
    } else {
      std::cout << lines_[i];
    }

    std::cout << std::endl;
  }

  std::cout << std::endl
            << "position: line " << (cursor_row_ + 1) << ", position "
            << cursor_col_ << std::endl;
}

void TextEditor::RunInteractive() {
  std::cout << "type smth..." << std::endl << std::endl;

  RefreshDisplay();

  while (true) {
    char key = _getch();

    if (key == 27) {
      break;
    } else if (key == 0 || key == -32) {
      key = _getch();
      HandleKeyPress(key);
    } else {
      HandleKeyPress(key);
    }
  }

  std::cout << std::endl << "work ended" << std::endl;
}

void TextEditor::PrintText() { RefreshDisplay(); }

std::string TextEditor::GetFullText() {
  std::string result;
  for (int i = 0; i < lines_.size(); i++) {
    result += lines_[i];
    if (i < lines_.size() - 1) {
      result += "\n";
    }
  }
  return result;
}

std::pair<int, int> TextEditor::GetCursorPosition() {
  return std::make_pair(cursor_row_, cursor_col_);
}