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

struct seg_tree {
  using ll = long long;
  using upd = std::plus<ll>;
  using lazy_upd = std::multiplies<ll>;
  struct combine {
    ll operator()(ll a, ll b) { return min(a, b); }
  };

  int n;
  vector<ll> t, lazy;
  seg_tree(int n) : n(n), t(4 * n + 1, 0), lazy(4 * n + 1) {}

  void prop(int ind, int l, int r) {
    if (!lazy[ind])
      return;
    t[ind] = upd()((r - l + 1) * lazy[ind], t[ind]);
    if (l == r)
      return;
    lazy[2 * ind + 1] += lazy[ind];
    lazy[2 * ind + 2] += lazy[ind];
    lazy[ind] = 0;
  }

  inline void range_update(int l, int r, int val) {
    range_update(l, r, 0, n - 1, 0, val);
  }
  void range_update(int l, int r, int tl, int tr, int ind, int delta) {
    prop(ind, tl, tr);
    if (l > r)
      return;
    if (l == tl && r == tr) {
      lazy[ind] = delta;
      prop(ind, tl, tr);
    } else {
      int m = (tl + tr) / 2;
      range_update(l, min(r, m), tl, m, 2 * ind + 1, delta);
      range_update(max(l, m + 1), r, m + 1, tr, 2 * ind + 2, delta);
      t[ind] = combine()(t[2 * ind + 1], t[2 * ind + 2]);
    }
  }

  inline ll query(int l, int r) { return query(l, r, 0, n - 1, 0); }

  ll query(int l, int r, int tl, int tr, int ind) {
    prop(ind, tl, tr);
    if (l > r)
      return 0;
    if (tl == l && tr == r) {
      return t[ind];
    } else {
      int tm = (tl + tr) / 2;
      auto x = query(l, min(tm, r), tl, tm, 2 * ind + 1);
      auto y = query(max(l, tm + 1), r, tm + 1, tr, 2 * ind + 2);
      return combine()(x, y);
    }
  }
};

int main() {}
