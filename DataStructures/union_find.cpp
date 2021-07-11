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

// union find with rank
unordered_map<int, int> par;
unordered_map<int, int> rnk;

int find_set(int s) {
  if (par[s] == s) {
    return s;
  }
  return par[s] = find_set(par[s]);
}

void union_set(int a, int b) {
  int x = find_set(a);
  int y = find_set(b);
  if (x != y) {
    if (rnk[x] < rnk[y]) {
      swap(x, y);
    }
    par[y] = x;
    if (rnk[x] == rnk[y]) {
      rnk[x]++;
    }
  }
}

int main() {}
