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
  void f(vector<vector<int>> &ans, vector<int> &x) {
    if (ans.empty()) {
      ans.push_back(x);
      return;
    }
    auto &back = ans.back();
    if (x[0] <= back[1]) {
      back[0] = min(x[0], back[0]);
      back[1] = max(x[1], back[1]);
    } else {
      ans.push_back(x);
    }
    return;
  }
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    vector<vector<int>> ans;
    if (intervals.empty()) {
      ans.push_back(newInterval);
      return ans;
    }
    auto y = newInterval;
    bool pushed = false;
    for (auto &x : intervals) {
      if (x < y) {
        f(ans, x);
      } else {
        f(ans, y);
        if (!pushed)
          y = x;
      }
      auto &back = ans.back();
      if (!pushed && y[0] <= back[1]) {
        back[0] = min(y[0], back[0]);
        back[1] = max(y[1], back[1]);
        y[0] = INT32_MAX;
        y[1] = INT32_MAX;
        pushed = true;
      }
    }
    if (!pushed) {
      ans.push_back(y);
    }
    return ans;
  }
};

int main() {}
