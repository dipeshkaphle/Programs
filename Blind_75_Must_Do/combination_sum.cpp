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
  set<vector<int>> ans;
  void solve(vector<int> &cand, int i, int tgt, vector<int> &cur) {
    if (tgt == 0) {
      ans.insert(cur);
      return;
    }
    if (i >= cand.size()) {
      return;
    }
    if (tgt >= cand[i]) {
      cur.push_back(cand[i]);
      solve(cand, i, tgt - cand[i], cur);
      cur.pop_back();
    }
    solve(cand, i + 1, tgt, cur);
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    ans.clear();
    vector<int> cur;
    solve(candidates, 0, target, cur);
    return vector<vector<int>>(ans.begin(), ans.end());
  }
};

int main() {}
