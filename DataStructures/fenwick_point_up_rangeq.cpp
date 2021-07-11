#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = size_t;
using ll = long long;
template <typename T> using Vec = std::vector<T>;
template <typename T> using o_set = std::set<T>;
template <typename T> using u_set = std::unordered_set<T>;
template <typename K, typename V> using u_map = std::unordered_map<K, V>;
template <typename K, typename V> using o_map = std::map<K, V>;
using namespace std;

struct fen_tree {
  using ll = long long;
  vector<ll> t;
  size_t n;
  fen_tree(size_t n) : n(n), t(n + 1, 0) {}
  fen_tree(const vector<ll> &vec) : fen_tree(vec.size()) {
    /*
     * // nlogn  construction
     * // but there's a linear algorithm as well
     * for (int i = 1; i <= n; i++) {
     *   update(i, vec[i - 1]);
     * }
     */

    // linear construction, only possible for point update, range query variant
    for (size_t i = 1; i <= n; i++) {
      t[i] += vec[i - 1];
      size_t j = i + (i & -i);
      if (j <= n)
        t[j] += t[i];
    }
  }
  void point_update(size_t ind, ll val) {
    for (; ind <= n; ind += (ind & -ind)) {
      t[ind] += val;
    }
  }
  ll query(size_t ind) {
    ll sum = 0;
    for (; ind > 0; ind -= (ind & -ind))
      sum += t[ind];
    return sum;
  }

  ll range_query(size_t l, size_t r) { return query(r) - query(l - 1); }
};

int main() {
  vector<ll> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  fen_tree f(vec);
  cout << f.query(10) << '\n';
  f.point_update(1, 2);
  cout << f.range_query(1, 3) << '\n';
  cout << f.range_query(1, 10) << '\n';
  cout << f.range_query(2, 2) << '\n';
}
