#include "codeforces-cpp/58a/p58a_solution.h"
#include <algorithm>   // std::find
#include <iostream>    // std::cout, std::cin
#include <iterator>    // std::next
#include <string>      // std::getline, std::string
#include <string_view> // std::string_view

constexpr auto look_for{std::string_view{"hello"}};

namespace p58a {
void solution() {
  std::string input;
  std::getline(std::cin, input);

  auto input_it{input.begin()};
  auto look_for_it{look_for.begin()};

  while (input_it != input.end() && look_for_it != look_for.end()) {

    input_it = std::find(input_it, input.end(), *look_for_it);

    // We have to be not at the end of input to safely call std::next
    if (input_it == input.end()) {
      break;
    }

    input_it = std::next(input_it);
    look_for_it = std::next(look_for_it);
  }

  std::cout << (look_for_it == look_for.end() ? "YES" : "NO");
}
} // namespace p58a
