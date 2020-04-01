#include "codeforces-cpp/133a/p133a_solution.h"
#include <algorithm> // std::any_of
#include <iostream>  // std::cout, std::cin
#include <string>    // std::string, std::getline

namespace p133a {
void solution() {
  std::string input;
  std::getline(std::cin, input);

  auto result{std::any_of(input.begin(), input.end(), [&](unsigned char c) {
    return c == 'H' || c == 'Q' || c == '9';
  })};

  std::cout << (result ? "YES" : "NO");
}
} // namespace p133a
