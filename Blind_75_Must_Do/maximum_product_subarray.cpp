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
  int maxProduct(vector<int> &nums) {
    int cur_min = nums[0];
    int max_ = nums[0];
    int cur_max = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int tmp = cur_max;
      cur_max = max({cur_max * nums[i], nums[i], cur_min * nums[i]});
      max_ = max(cur_max, max_);
      cur_min = min({cur_min * nums[i], nums[i], tmp * nums[i]});
    }
    return max_;
  }
};
int main() {}
