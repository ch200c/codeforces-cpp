#include "codeforces-cpp/158b/p158b_solution.h"
#include <algorithm>  // std::find_if
#include <functional> // std::greater
#include <iostream>   // std::cout, std::cin
#include <iterator>   // std::istream_iterator
#include <sstream>    // std::istringstream
#include <string>     // std::string, std::getline
#include <vector>     // std::vector

namespace p158b {
void solution() {
  int n;
  std::cin >> n >> std::ws;

  std::string input;
  std::getline(std::cin, input);

  auto stream{std::istringstream{input}};
  auto counts{std::vector<int>{std::istream_iterator<int>{stream},
                               std::istream_iterator<int>{}}};

  // Descending sort
  std::sort(counts.begin(), counts.end(), std::greater<int>{});

  auto taxi_count{0};

  while (!counts.empty()) {

    auto free_seat_count{4};

    while (free_seat_count > 0) {

      auto it{std::find_if(counts.begin(), counts.end(), [&](int count) {
        return count <= free_seat_count;
      })};

      if (it == counts.end()) {
        break;
      }

      free_seat_count -= *it;
      counts.erase(it);
    }

    ++taxi_count;
  }

  std::cout << taxi_count;
}
} // namespace p158b
