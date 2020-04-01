#include "codeforces-cpp/131a/p131a_solution.h"
#include <algorithm> // std::all_of, std::transform
#include <cctype>    // std::isupper, std::tolower, std::toupper
#include <iostream>  // std::cout, std::cin
#include <iterator>  // std::next
#include <string>    // std::string, std::getline

namespace p131a {
void solution() {
  std::string input;
  std::getline(std::cin, input);

  auto are_all_except_first_capital{
      std::all_of(std::next(input.begin()), input.end(),
                  [&](unsigned char c) { return std::isupper(c); })};

  auto are_all_capital{are_all_except_first_capital &&
                       std::isupper(*input.begin())};

  if (are_all_except_first_capital || are_all_capital) {
    std::transform(
        input.begin(), input.end(), input.begin(), [&](unsigned char c) {
          return std::isupper(c) ? static_cast<unsigned char>(std::tolower(c))
                                 : static_cast<unsigned char>(std::toupper(c));
        });
  }

  std::cout << input;
}
} // namespace p131a
