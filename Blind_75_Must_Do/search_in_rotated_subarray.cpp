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
  int search(vector<int> &nums, int target) {
    int lst = nums.back();
    int l = -1;
    int r = nums.size() - 1;
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (nums[m] > lst) {
        l = m;
      } else {
        r = m;
      }
    }
    auto pivot = nums.begin() + l + 1;
    auto it = lower_bound(nums.begin(), pivot, target);
    if (it != nums.end() && *it == target) {
      return distance(nums.begin(), it);
    }
    it = lower_bound(pivot, nums.end(), target);
    if (it != nums.end() && *it == target) {
      return distance(nums.begin(), it);
    }
    return -1;
  }
};

int main() {}
