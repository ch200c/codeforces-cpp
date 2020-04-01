#include "codeforces-cpp/160a/p160a_solution.h"
#include <algorithm>  // std::sort
#include <functional> // std::greater
#include <iostream>   // std::cout, std::cin
#include <iterator>   // std::istream_iterator
#include <numeric>    // std::accumulate
#include <sstream>    // std::istringstream
#include <string>     // std::string, std::getline
#include <vector>     // std::vector

namespace p160a {
void solution() {
  int n;
  std::cin >> n >> std::ws;

  std::string input;
  std::getline(std::cin, input);

  auto stream{std::istringstream{input}};
  auto coins{std::vector<int>{std::istream_iterator<int>{stream},
                              std::istream_iterator<int>{}}};

  // Descending sort
  std::sort(coins.begin(), coins.end(), std::greater<int>{});

  auto taken_coins{std::vector<int>{}};

  while (std::accumulate(coins.begin(), coins.end(), 0) >=
         std::accumulate(taken_coins.begin(), taken_coins.end(), 0)) {

    auto it{coins.begin()};
    taken_coins.emplace_back(*it);
    coins.erase(it);
  }

  std::cout << taken_coins.size();
}
} // namespace p160a
