
#include <vector>
#include <string>
#include "../../utils.cpp"


int main() {
    // Your code here
    std::vector<std::string> rows = get_input_rows_from_stdin();

    int dial_val = 50;

    int zero_counts = 0;

    for (std::string row : rows) {
      char direction = row[0];
      std::string padded_string_amount = left_pad(row.substr(1), '0', 2);
      int turn_amount = std::stoi(get_last_x_chars(padded_string_amount, 2));
      int new_val = 0;

      if (direction == 'R') {
        new_val = dial_val + turn_amount;
      } else {
        // additional 100 added to compensate for negative values
        new_val = dial_val - turn_amount + 100;  
      }

      dial_val = new_val % 100;

      if (dial_val == 0) {
        zero_counts++;
      }
    }

    std::cout << zero_counts << std::endl;

    return 0;
}