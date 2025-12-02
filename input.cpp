#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> get_input_values_from_stdin_by_delimiter(char delimiter) {
  std::vector<std::string> ranges;
  std::string range;

  while (std::getline(std::cin, range, delimiter)) {
    ranges.push_back(range);
  }

  return ranges; 
}

std::vector<std::string> get_input_rows_from_stdin() {
  return get_input_values_from_stdin_by_delimiter('\n');
}