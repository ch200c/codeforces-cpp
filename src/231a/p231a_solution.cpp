#include "codeforces-cpp/231a/p231a_solution.h"
#include <algorithm> // std::count
#include <iostream>  // std::cin, std::cout
#include <iterator>  // std::istream_iterator
#include <sstream>   // std::istringstream
#include <string>    // std::getline
#include <vector>    // std::vector

namespace p231a {
void solution() {

  int n;
  std::cin >> n;
  ptrdiff_t count{0};

  for (auto i{0}; i <= n; ++i) {

    std::string line;
    std::getline(std::cin, line);

    auto stream{std::istringstream{line}};
    auto flags{std::vector<int>{std::istream_iterator<int>{stream},
                                std::istream_iterator<int>{}}};

    auto ones_count{std::count(flags.begin(), flags.end(), 1)};

    if (ones_count >= 2) {
      ++count;
    }
  }

  std::cout << count;
}
} // namespace p231a
