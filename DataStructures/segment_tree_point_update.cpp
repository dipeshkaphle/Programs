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
  using ret_type = long long;
  using combine = std::plus<ret_type>;
  using update_func = std::plus<ret_type>;

  /*
   * attributes
   */
  ret_type default_val = ret_type();
  vector<ret_type> t;
  size_t n;

  seg_tree(size_t n) : n(4 * n) { t.assign(this->n + 5, 0); }
  seg_tree(const vector<ret_type> &vec) : seg_tree(vec.size()) {
    build(vec, 0, 0, n - 1);
  }
  void build(const vector<ret_type> &vec, size_t ind, size_t t_l, size_t t_r) {
    if (t_l == t_r) {
      t[ind] = vec[t_l];
    } else {
      size_t m = (t_l + t_r) / 2;
      build(vec, 2 * ind + 1, t_l, m);
      build(vec, 2 * ind + 2, m + 1, t_r);
      t[ind] = combine()(t[2 * ind + 1], t[2 * ind + 2]);
    }
  }

  void point_update(size_t ind, ret_type new_val, size_t t_ind, size_t t_l,
                    size_t t_r) {
    if (t_l == t_r) {
      t[t_ind] = update_func()(t[t_ind], new_val);
    } else {
      size_t m = (t_l + t_r) / 2;
      if (ind <= m)
        point_update(ind, new_val, 2 * t_ind + 1, t_l, m);
      else
        point_update(ind, new_val, 2 * t_ind + 2, m + 1, t_r);
      t[t_ind] = combine()(t[2 * t_ind + 1], t[2 * t_ind + 2]);
    }
  }

  ret_type range_query(size_t l, size_t r, size_t t_l, size_t t_r, size_t ind) {
    if (l > r)
      return default_val;
    if (t_l == l && t_r == r)
      return t[ind];
    size_t m = (t_l + t_r) / 2;
    auto x = range_query(l, r, t_l, min(t_r, m), 2 * ind + 1);
    auto y = range_query(l, r, max(t_l, m + 1), t_r, 2 * ind + 2);
    return combine()(x, y);
  }
};

int main() {}
