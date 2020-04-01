#include "codeforces-cpp/677a/p677a_solution.h"
#include <algorithm> // std::count_if
#include <iostream>  // std::cout, std::cin
#include <istream>   // std::ws
#include <iterator>  // std::istream_iterator
#include <sstream>   // std::istringstream
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

namespace p677a {
void solution() {
  int n;
  int h;
  std::cin >> n >> h >> std::ws;

  std::string line;
  std::getline(std::cin, line);

  auto stream{std::istringstream{line}};
  auto heights{std::vector<int>{std::istream_iterator<int>{stream},
                                std::istream_iterator<int>{}}};
  auto tall_count{
      std::count_if(heights.cbegin(), heights.cend(),
                    [&](const auto &height) { return height > h; })};

  auto small_count{n - tall_count};
  auto road_width{small_count + (tall_count * 2)};

  std::cout << road_width;
}
} // namespace p677a
