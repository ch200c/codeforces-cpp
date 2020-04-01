#include "codeforces-cpp/405a/p405a_solution.h"
#include <algorithm> // std::max_element, std::partition, std::copy
#include <iostream>  // std::cout, std::cin
#include <iterator>  // std::istream_iterator, std::ostream_iterator
#include <sstream>   // std::istringstream
#include <string>    // std::getline, std::string
#include <vector>    // std::vector

namespace p405a {
void solution() {
  int n;
  std::cin >> n >> std::ws;

  std::string line;
  std::getline(std::cin, line);

  auto stream{std::istringstream(line)};
  auto cube_counts{std::vector<int>(std::istream_iterator<int>(stream),
                                    std::istream_iterator<int>())};

  // Preventing C26451 in later for loop
  auto max_cube_count{static_cast<size_t>(
      *std::max_element(cube_counts.cbegin(), cube_counts.cend()))};

  // Represents the cube columns. max_cube_count - count elements are filled
  // from the top with false and remaining are true.
  std::vector<std::vector<bool>> columns;

  for (const auto &count : cube_counts) {
    auto column{std::vector<bool>(max_cube_count - count, false)};
    column.insert(column.cend(), count, true);

    columns.push_back(column);
  }

  auto new_counts{std::vector<int>(n, 0)};

  // Loop from top to down
  for (auto i{0}; i < max_cube_count; ++i) {

    std::vector<bool> row;

    for (auto j{0}; j < n; ++j) {
      row.push_back(columns[j][i]);
    }

    // Order false values first
    std::partition(row.begin(), row.end(),
                   [&](const auto &value) { return !value; });

    for (auto j{0}; j < n; ++j) {
      if (row[j]) {
        ++new_counts[j];
      }
    }
  }

  std::copy(new_counts.cbegin(), new_counts.cend(),
            std::ostream_iterator<int>(std::cout, " "));
}
} // namespace p405a
