#include "number_iterator.hpp"
#include <algorithm>
#include <iostream>
#include <utility>

ll num = 4;
bool isBadVersion(ll x) {
  if (x > num) {
    return true;
  }
  return false;
}
template <class ForwardIt, class T, class Compare>
ForwardIt l_b(ForwardIt first, ForwardIt last, const T &value, Compare comp) {
  ForwardIt it = ForwardIt();
  typename std::iterator_traits<ForwardIt>::difference_type count, step;
  count = std::distance(first, last);

  while (count > 0) {
    it = first;
    step = count / 2;
    std::advance(it, step);
    if (comp(*it, value)) {
      first = ++it;
      count -= step + 1;
    } else
      count = step;
  }
  return first;
}

class Solution {
public:
  int firstBadVersion(int n) {
    auto rng = range(0, ((long long)n) + 1);
    auto it = std::lower_bound(rng.begin(), rng.end(), true, [](ll x, bool y) {
      return isBadVersion(x) != y;
    });
    return it - rng.begin();
  }
};

int main() {
  auto s = Solution();
  std::cout << s.firstBadVersion(5) << '\n';
}
