#include "codeforces-cpp/344a/p344a_solution.h"
#include <iostream> // std::cout, std::cin

enum class Polarity { None, Negative, Positive };

namespace p344a {
void solution() {
  int n;
  std::cin >> n;

  auto previous_polartiy{Polarity::None};
  auto group_count{0};

  for (auto i{0}; i < n; ++i) {
    int polarity;
    std::cin >> polarity;

    if (polarity == 10) {
      if (previous_polartiy != Polarity::Negative) {
        ++group_count;
      }

      previous_polartiy = Polarity::Negative;

    } else {
      if (previous_polartiy != Polarity::Positive) {
        ++group_count;
      }

      previous_polartiy = Polarity::Positive;
    }
  }

  std::cout << group_count;
}
} // namespace p344a
