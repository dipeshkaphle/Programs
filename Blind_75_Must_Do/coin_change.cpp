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
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<long long> dp(amount + 1, INT32_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (auto x : coins) {
        if (i >= x) {
          dp[i] = min(dp[i], dp[i - x] + 1);
        }
      }
    }
    if (dp.back() >= INT32_MAX) {
      return -1;
    } else {
      return dp.back();
    }
  }
};
int main() {}
