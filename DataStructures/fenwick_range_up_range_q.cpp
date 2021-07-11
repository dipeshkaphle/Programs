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

// https://stackoverflow.com/questions/27875691/need-a-clear-explanation-of-range-updates-and-range-queries-binary-indexed-tree/27877427#27877427

struct fen_tree {
  using ll = long long;
  vector<ll> t1, t2;
  size_t n;
  fen_tree(size_t n) : n(n), t1(n + 1, 0), t2(n + 1, 0) {}
  fen_tree(const vector<ll> &vec) : fen_tree(vec.size()) {

    // nlogn  construction
    for (int i = 1; i <= n; i++) {
      range_update(i, i, vec[i - 1]);
    }
  }

  void _update(vector<ll> &t, size_t ind, ll x) {
    for (; ind <= n; ind += (ind & -ind))
      t[ind] += x;
  }
  ll _sum(vector<ll> &t, size_t ind) {
    ll sum = 0;
    for (; ind > 0; ind -= (ind & -ind))
      sum += t[ind];
    return sum;
  }

  void range_update(size_t l, size_t r, ll val) {
    _update(t1, l, val);
    _update(t1, r + 1, -val);

    _update(t2, l, val * (l - 1));
    _update(t2, r + 1, -val * r);
  }
  ll prefix_sum(size_t ind) { return _sum(t1, ind) * ind - _sum(t2, ind); }
  ll range_sum(size_t l, size_t r) { return prefix_sum(r) - prefix_sum(l - 1); }
};

int main() {
  vector<ll> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  fen_tree f(vec);
  cout << f.range_sum(3, 3) << '\n';
  f.range_update(1, 5, 2);
  cout << f.range_sum(3, 3) << '\n';
  cout << f.range_sum(2, 2) << '\n';
  cout << f.range_sum(6, 6) << '\n';
}
