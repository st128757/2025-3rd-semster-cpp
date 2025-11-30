#include <cmath>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

bool IsOperator(const std::string& symbol) {
  return symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/" ||
         symbol == "^";
}

bool IsNumber(const std::string& symbol) {
  if (symbol.empty()) {
    return false;
  }

  bool has_decimal = false;
  int start = 0;
  if (symbol[0] == '-' && symbol.size() > 1 && symbol[1] != ' ') {
    ++start;
  }

  for (int i = start; i < symbol.size(); ++i) {
    char c = symbol[i];

    if (c == '.') {
      if (has_decimal) return false;
      has_decimal = true;
    } else if (c < '0' || c > '9') {
      return false;
    }
  }

  return true;
}

double StringToDouble(const std::string& symbol) {
  double result = 0.0;
  double decimal_part = 0.0;
  double sign = 1.0;
  bool after_decimal = false;
  double decimal_place = 1.0;

  int start = 0;
  if (symbol[0] == '-') {
    sign = -1.0;
    start = 1;
  } else if (symbol[0] == '+') {
    start = 1;
  }

  for (int i = start; i < symbol.size(); ++i) {
    char c = symbol[i];

    if (c == '.') {
      after_decimal = true;
    } else {
      int digit = c - '0';
      if (after_decimal) {
        decimal_place *= 10.0;
        decimal_part = decimal_part * 10.0 + digit;
      } else {
        result = result * 10.0 + digit;
      }
    }
  }

  return sign * (result + decimal_part / decimal_place);
}

double PerformOperation(double a, double b, const std::string& symbol,
                        bool* error, std::string* error_msg) {
  *error = false;

  if (symbol == "+") return a + b;
  if (symbol == "-") return a - b;
  if (symbol == "*") return a * b;
  if (symbol == "/") {
    if (b == 0.0) {
      *error = true;
      *error_msg = "Division by zero";
      return 0.0;
    }
    return a / b;
  }
  if (symbol == "^") {
    return std::pow(a, b);
  }

  *error = true;
  *error_msg = "Unknown operator: " + symbol;
  return 0.0;
}

double Evaluate(const std::string& expression, bool* error,
                std::string* error_msg) {
  std::stack<double> stack;
  *error = false;
  *error_msg = "";

  // Объявление symbol перемещено внутрь цикла или в место первого использования
  // для сужения области видимости (исправление variableScope).
  int pos = 0;

  while (pos < expression.size()) {
    while (pos < expression.size() && expression[pos] == ' ') {
      ++pos;
    }
    if (pos >= expression.size()) break;

    int symbol_start = pos;
    while (pos < expression.size() && expression[pos] != ' ') {
      ++pos;
    }

    // Объявление symbol здесь, в месте, где она используется.
    std::string symbol = expression.substr(symbol_start, pos - symbol_start);

    if (symbol.empty()) {
      continue;
    }

    if (IsOperator(symbol)) {
      if (stack.size() < 2) {
        *error = true;
        *error_msg = "Not enough numbers for operation: " + symbol;
        return 0.0;
      }

      double b = stack.top();
      stack.pop();
      double a = stack.top();
      stack.pop();

      bool operation_error = false;
      std::string op_error_msg;
      double result =
          PerformOperation(a, b, symbol, &operation_error, &op_error_msg);

      if (operation_error) {
        *error = true;
        *error_msg = op_error_msg;
        return 0.0;
      }

      stack.push(result);
    } else if (IsNumber(symbol)) {
      double num = StringToDouble(symbol);
      stack.push(num);
    } else {
      *error = true;
      *error_msg = "Incorrect symbol: " + symbol;
      return 0.0;
    }
  }

  if (stack.size() != 1) {
    *error = true;
    *error_msg = "Incorrect expression";
    return 0.0;
  }

  return stack.top();
}

std::string DoubleToString(double res) {
  std::string str = std::to_string(res);
  int dot_pos = str.find('.');

  if (dot_pos != std::string::npos) {
    // Исправление uselessCallsSubstr: Используем resize() вместо substr
    // для удаления конечных нулей.
    size_t last_non_zero = str.find_last_not_of('0');
    if (last_non_zero != std::string::npos) {
      str.resize(last_non_zero + 1);
    }

    if (str.back() == '.') {
      str.pop_back();
    }
  }
  return str;
}

void ProcessFile(const std::string& in_path, const std::string& out_path) {
  std::ifstream input_file(in_path);
  std::ofstream output_file(out_path);

  if (!input_file.is_open()) {
    std::cout << "Error: Input file '" << in_path << "' isn't open"
              << std::endl;
    return;
  }
  if (!output_file.is_open()) {
    std::cout << "Error: Output file '" << out_path << "' isn't open"
              << std::endl;
    return;
  }

  std::string line;
  int line_number = 0;

  while (std::getline(input_file, line)) {
    line_number++;

    if (line.empty()) {
      continue;
    }

    bool error = false;
    std::string error_msg;
    double result = Evaluate(line, &error, &error_msg);

    if (error) {
      output_file << "ERROR: " << error_msg << "\n";
      std::cout << "failure in line " << line_number << ": " << error_msg
                << std::endl;
    } else {
      std::string formatted_result = DoubleToString(result);
      output_file << line << " = " << formatted_result << "\n";
      std::cout << line_number << ": " << line << " = " << formatted_result
                << std::endl;
    }
  }
}

int main() {
  const std::string kInputPath = "C:/input.txt";
  const std::string kOutputPath = "C:/output.txt";

  ProcessFile(kInputPath, kOutputPath);

  return 0;
}
