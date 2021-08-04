#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
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

template <typename It, typename F> struct sparse_table {
  using T = remove_reference_t<decltype(*declval<It>())>;
  template <typename U> using Vec = vector<U>;
  Vec<Vec<T>> tab;
  int n;
  F f;
  // template <typename Iterator, typename G>
  sparse_table(It fst, It lst, F g) : f(g) {
    n = distance(fst, lst);
    int rows = log2(n);
    tab = Vec<Vec<T>>(rows + 1, Vec<T>(n));
    copy(fst, lst, tab[0].begin());
    for (int r = 1; r <= rows; r++) {
      for (int i = 0; (i + (1 << r)) <= n; i++) {
        tab[r][i] = f(tab[r - 1][i], tab[r - 1][i + (1 << (r - 1))]);
      }
    }
  }
  T query(int l, int r) {
    int x = log2(r - l + 1);
    return f(tab[x][l], tab[x][r - ((1 << x) - 1)]);
  }
};
int main() {}
