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

