#include "codeforces-cpp/208a/p208a_solution.h"
#include <algorithm> // std::copy
#include <iostream>  // std::cout
#include <iterator>  // std::istream_iterator, std::ostream_iterator
#include <regex>     // std::regex_replace, std::regex
#include <sstream>   // std::istringstream
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

namespace p208a {
void solution() {

  std::string input;
  std::getline(std::cin, input);

  auto input_with_no_wubs{std::regex_replace(input, std::regex("WUB"), " ")};

  auto stream{std::istringstream(input_with_no_wubs)};

  // Reads in the words with whitespace delimiter
  auto words{
      std::vector<std::string>(std::istream_iterator<std::string>(stream),
                               std::istream_iterator<std::string>())};

  std::copy(words.cbegin(), words.cend(),
            std::ostream_iterator<std::string>(std::cout, " "));
}
} // namespace p208a
