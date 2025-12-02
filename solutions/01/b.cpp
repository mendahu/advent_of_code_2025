
#include <vector>
#include <string>
#include "../../input.cpp"
#include "../../utils.cpp"


std::string get_all_chars_except_last_x(std::string value, int x) {
  return value.substr(0, value.length() - x);
}

bool has_crossed_zero(int start_val, int end_val) {
  return (start_val != 0 && end_val < 0) || end_val == 0 || end_val >= 100;
}

int main() {
    // Your code here
    std::vector<std::string> rows = get_input_rows_from_stdin();

    int dial_val = 50;

    int zero_counts = 0;

    for (std::string row : rows) {
      // direction is either 'R' or 'L'
      char direction = row[0];

      // amount to turn dial, padded to 3 digits
      std::string string_amount = row.substr(1);
      std::string padded_string_amount = left_pad(string_amount, '0', 3);

      // amount to turn dial, last 2 digits
      int turn_amount = std::stoi(get_last_x_chars(padded_string_amount, 2));

      // amount to turn dial, all digits except last 2 (to count full rotations beyond difference)
      int full_rotation_count = std::stoi(get_all_chars_except_last_x(padded_string_amount, 2));

      // add full rotations to zero counts
      zero_counts += full_rotation_count;

      int new_val = 0;

      if (direction == 'R') {
        new_val = dial_val + turn_amount;
      } else {
        new_val = dial_val - turn_amount;  
      }

      // have we crossed a zero?
      if (has_crossed_zero(dial_val, new_val)) {
        zero_counts++;
      }
      
      // additional 100 added to compensate for negative values
      dial_val = (new_val + 100) % 100;
    }

    std::cout << zero_counts << std::endl;

    return 0;
}