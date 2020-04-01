#include "codeforces-cpp/96a/p96a_solution.h"
#include <algorithm> // std::search_n
#include <iostream>  // std::cout
#include <string>    // std::getline

namespace p96a {
void solution() {
  std::string players;
  std::getline(std::cin, players);

  auto consecutive_zeroes{
      std::search_n(players.begin(), players.end(), 7, '0')};

  auto consecutive_ones{std::search_n(players.begin(), players.end(), 7, '1')};

  auto result{consecutive_zeroes != players.end() ||
                      consecutive_ones != players.end()
                  ? "YES"
                  : "NO"};

  std::cout << result;
}
} // namespace p96a
