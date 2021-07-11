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
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), INT32_MAX);
    vector<int> parent(nums.size(), -1);
    vector<int> index(nums.size(), -1);
    auto len = 0;
    for (int i = 0; i < nums.size(); i++) {
      auto val = nums[i];
      auto it = lower_bound(nums.begin(), nums.begin() + len, nums[i]);
      int ind = distance(nums.begin(), it);
      *it = val;
      index[ind] = i;
      parent[i] = ind > 0 ? index[ind - 1] : -1;
      if (ind == len) {
        len++;
      }
    }
    vector<int> ans;
    int num = index[len - 1];
    while (num != -1) {
      ans.push_back(nums[num]);
      num = parent[num];
    }
    reverse(ans.begin(), ans.end());
    return ans.size();
  }
};

int main() {}
