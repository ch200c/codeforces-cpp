#include "codeforces-cpp/705a/p705a_solution.h"
#include <iostream>    // std::cout, std::cin
#include <sstream>     // std::stringstream
#include <string_view> // std::string_view

constexpr std::string_view verb(const int i) noexcept {
  return i % 2 ? "hate" : "love";
}
namespace p705a {
void solution() {
  int n;
  std::cin >> n;

  std::stringstream stream;
  for (auto i{1}; i <= n - 1; ++i) {
    stream << "I " << verb(i) << " that ";
  }

  stream << "I " << verb(n) << " it";

  std::cout << stream.str();
}
} // namespace p705a
