#include "codeforces-cpp/236a/p236a_solution.h"
#include <iostream> // std::cout, std::cin
#include <set>      // std::set
#include <string>   // std::getline, std::string

namespace p236a {
void solution() {
  std::string name;
  std::getline(std::cin, name);

  auto distinct_chars{std::set<char>{name.begin(), name.end()}};
  auto result{distinct_chars.size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!"};

  std::cout << result;
}
} // namespace p236a
