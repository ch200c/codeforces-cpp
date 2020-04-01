#include "codeforces-cpp/1030a/p1030a_solution.h"
#include <algorithm>  // std::all_of
#include <functional> // std::logical_not
#include <iostream>   // std::cout, std::cin
#include <istream>    // std::ws
#include <iterator>   // std::istream_iterator
#include <sstream>    // std::istringstream
#include <string>     // std::string, std::getline
#include <vector>     // std::vector

namespace p1030a {
void solution() {

  int n;
  std::cin >> n >> std::ws;

  std::string input;
  std::getline(std::cin, input);

  auto stream{std::istringstream(input)};
  auto opinions{std::vector<bool>(std::istream_iterator<bool>(stream),
                                  std::istream_iterator<bool>())};

  auto is_hard{!std::all_of(opinions.cbegin(), opinions.cend(),
                            std::logical_not<bool>())};

  std::cout << (is_hard ? "HARD" : "EASY");
}
} // namespace p1030a
