#include <vector>
#include <string>
#include "../../input.cpp"
#include "../../utils.cpp"

// this code is horrific

std::vector<std::string> split_string_in_equal_parts(std::string input, int count) {
  std::vector<std::string> parts;

  int part_len = input.length() / count;
  for (int i = 0; i < count; i++) {
    parts.push_back(input.substr(i * part_len, part_len));
  }
  return parts;
}

bool all_vector_values_are_equal(std::vector<std::string>* values) {
  int size = values->size();
  for (std::string value : *values) {
    if (value != (*values)[size - 1]) {
      return false;
    }
  }
  return true;
}

bool string_has_all_repeating_values(std::string value) {
  int len = value.length();

  if (len < 2) {
    return false;
  }

  for (int j = 2; j <= len; j++) {
    std::vector<std::string> parts;

    if (len % j != 0) {
      continue;
    }

    parts = split_string_in_equal_parts(value, j);

    if (all_vector_values_are_equal(&parts)) {
      return true;
    }
  }

  return false;
}

int main() {
  std::vector<std::string> ranges = get_input_values_from_stdin_by_delimiter(',');

  int64_t sum = 0;

  for (std::string range : ranges) {
    std::vector<std::string> range_values = split_string(range, '-');
    int64_t start = std::stoll(range_values[0]);
    int64_t end = std::stoll(range_values[1]);

    for (int64_t i = start; i <= end; i++) {
      std::string i_string = std::to_string(i);

      
      if (string_has_all_repeating_values(i_string)) {
        sum += i;
        
      }
    }
  }

  std::cout << sum << std::endl;

  return 0;
}