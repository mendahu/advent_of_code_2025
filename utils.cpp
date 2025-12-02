#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> get_input_rows_from_stdin() {
  std::vector<std::string> rows;
  std::string row;
  
  while (std::getline(std::cin, row)) {
    rows.push_back(row);
  }

  return rows;
}

std::string left_pad(std::string value, char padding_char, int padding) {
  if (value.length() >= padding) {
    return value;
  }
  return std::string(padding - value.length(), padding_char) + value;
}

std::string get_last_x_chars(std::string value, int x) {
  return value.substr(value.length() - x);
}
