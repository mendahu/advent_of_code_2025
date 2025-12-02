
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
      int amount = std::stoi(row.substr(1));
      int mod_amount = amount % 100;
      int new_val = 0;

      if (direction == 'R') {
        new_val = dial_val + mod_amount;
        dial_val = new_val % 100;
      } else {
        new_val = dial_val - mod_amount;
        if (new_val < 0) {
          new_val += 100;
        }
        dial_val = new_val;
      }

      if (dial_val == 0) {
        zero_counts++;
      }
    }

    std::cout << zero_counts << std::endl;

    return 0;
}