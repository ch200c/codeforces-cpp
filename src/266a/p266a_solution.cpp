#include "codeforces-cpp/266a/p266a_solution.h"
#include <algorithm> // std::unique
#include <iostream>  // std::cout, std::cin
#include <istream>   // std::ws
#include <iterator>  // std::distance
#include <string>    // std::getline

namespace p266a {
void solution() {
  int n;
  std::cin >> n >> std::ws;

  std::string stones;
  std::getline(std::cin, stones);

  // std::unique removes *consecutive* duplicate elements in a range
  auto unique_end{std::unique(stones.begin(), stones.end())};
  auto unique_count{std::distance(stones.begin(), unique_end)};

  std::cout << n - unique_count;
}
} // namespace p266a
