#include "codeforces-cpp/271a/p271a_solution.h"
#include <iostream> // std::cout, std::cin
#include <set>      // std::set
#include <string>   // std::string, std::to_string

namespace p271a {
void solution() {
  int y;
  std::cin >> y;

  for (y = y + 1; y <= 9999; ++y) {

    auto year_chars{std::to_string(y)};
    auto unique_year_chars{
        std::set<char>{year_chars.begin(), year_chars.end()}};

    if (unique_year_chars.size() == 4) {
      std::cout << y;
      break;
    }
  }
}
} // namespace p271a
