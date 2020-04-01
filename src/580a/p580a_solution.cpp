#include "codeforces-cpp/580a/p580a_solution.h"
#include <algorithm> // std::is_sorted_until, std::max_element
#include <cstddef>   // std::ptrdiff_t
#include <iostream>  // std::cout, std::cin
#include <istream>   // std::ws
#include <iterator>  // std::distance, std::istream_iterator
#include <sstream>   // std::istringstream
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

namespace p580a {
void solution() {
  int n;
  std::cin >> n >> std::ws;

  std::string input;
  std::getline(std::cin, input);

  std::istringstream stream{input};
  auto profits{std::vector<int>{std::istream_iterator<int>{stream},
                                std::istream_iterator<int>{}}};

  std::vector<std::ptrdiff_t> consecutive_days;
  std::vector<int>::iterator last_it;

  for (auto it{profits.begin()}; it != profits.end(); it = last_it) {

    last_it = std::is_sorted_until(it, profits.end());

    auto count{std::distance(it, last_it)};

    consecutive_days.emplace_back(count);
  }

  std::cout << *std::max_element(consecutive_days.begin(),
                                 consecutive_days.end());
}
} // namespace p580a
