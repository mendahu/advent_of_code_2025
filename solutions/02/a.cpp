#include <vector>
#include <string>
#include "../../input.cpp"
#include "../../utils.cpp"

int main() {
  std::vector<std::string> ranges = get_input_values_from_stdin_by_delimiter(',');

  int64_t sum = 0;

  for (std::string range : ranges) {
    std::vector<std::string> range_values = split_string(range, '-');
    int64_t start = std::stoll(range_values[0]);
    int64_t end = std::stoll(range_values[1]);
    printf("start: %lld, end: %lld\n", start, end);

    for (int64_t i = start; i <= end; i++) {
      std::string i_string = std::to_string(i);

      int len = i_string.length();

      if (len % 2 != 0) {
        continue;
      }

      printf("checking %s\n", i_string.c_str());

      int mid = len / 2;
      std::string first_half = i_string.substr(0, mid);
      std::string second_half = i_string.substr(mid);
      
      if (first_half == second_half) {
        printf("found %s\n", i_string.c_str());
        sum += i;
      }
    }
  }

  std::cout << sum << std::endl;

  return 0;
}