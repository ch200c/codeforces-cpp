#include "codeforces-cpp/112A/p112a_solution.h"
#include <algorithm> // std::transform
#include <cctype>    // std::tolower
#include <iostream>  // std::cin, std::cout
#include <string>    // std::getline

void string_to_lower(std::string &input) {
  std::transform(
      input.begin(), input.end(), input.begin(),
      [&](unsigned char c) { return static_cast<char>(std::tolower(c)); });
}

namespace p112a {
void solution() {
  std::string first;
  std::getline(std::cin, first);

  std::string second;
  std::getline(std::cin, second);

  string_to_lower(first);
  string_to_lower(second);

  std::cout << first.compare(second);
}
} // namespace p112a
