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
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      int k = n - 1;
      while (j < k) {
        int tgt = nums[i] + nums[j] + nums[k];
        if (tgt == 0) {
          ans.insert({nums[i], nums[j], nums[k]});
          j++;
          k--;
        } else if (tgt > 0) {
          k--;
        } else {
          j++;
        }
      }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
  }
};

int main() {}
