
#include <string>
#include <vector>

std::string left_pad(std::string value, char padding_char, int padding) {
  if (value.length() >= padding) {
    return value;
  }
  return std::string(padding - value.length(), padding_char) + value;
}

std::string get_last_x_chars(std::string value, int x) {
  return value.substr(value.length() - x);
}

std::vector<std::string> split_string(std::string input, char delimiter) {
  std::vector<std::string> values;
  std::string current_value = input;

  while (current_value.find(delimiter) != std::string::npos) {
    values.push_back(current_value.substr(0, current_value.find(delimiter)));
    current_value = current_value.substr(current_value.find(delimiter) + 1);
  }
  values.push_back(current_value);
  return values;
}
