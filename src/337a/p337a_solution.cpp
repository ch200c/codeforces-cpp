#include "codeforces-cpp/337a/p337a_solution.h"
#include <algorithm> // std::sort, std::minmax_element, std::min_element
#include <iostream>  // std::cout, std::cin
#include <istream>   // std::ws
#include <iterator>  // std::istream_iterator
#include <sstream>   // std::istringstream
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

namespace p337a {
void solution() {
  int n;
  int m;
  std::cin >> n >> m >> std::ws;

  std::string line;
  std::getline(std::cin, line);

  auto stream{std::istringstream{line}};
  auto quantities{std::vector<int>{std::istream_iterator<int>{stream},
                                   std::istream_iterator<int>{}}};

  std::sort(quantities.begin(), quantities.end());

  auto minmax_diffs{std::vector<int>{}};

  // We have a window that is n elements. The last iterator where we can start
  // the window is n elements from the end.
  auto end_it{std::next(quantities.cend(), -n + 1ll)};

  for (auto it{quantities.cbegin()}; it != end_it; it = std::next(it)) {

    auto window_begin_it{it};
    auto window_end_it{it};
    std::advance(window_end_it, n);

    auto quantities_window{std::vector<int>{window_begin_it, window_end_it}};

    auto [min_m, max_m]{std::minmax_element(quantities_window.cbegin(),
                                            quantities_window.cend())};

    minmax_diffs.emplace_back(*max_m - *min_m);
  }

  std::cout << *std::min_element(minmax_diffs.cbegin(), minmax_diffs.cend());
}
} // namespace p337a
