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
/*
 * Rank is basically the upper bound for the number of times
 * we need to call find_set inorder to reach the group head
 *
 * Lets say I have a group 1->2 and another group 3<- 4
 * Now I union these two
 * Currently I need maximum of 1 level climbing up to reach the head for both
 * groups When there's union operation we make it
 *
 * 1-> 2
 * ^
 * |
 * 3 <-  4
 *
 * Now this led to the max climbing to be 2 and hence rank was increased
 * So the rank only ever increases when the groups we're merging have the same
 * rank , otherwise it wouldnt need one extra hop
 *
 *
 */
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
