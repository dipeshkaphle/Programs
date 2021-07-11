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
  bool canJump(vector<int> &nums) {
    if (nums.size() == 1)
      return true;
    int max_jump = nums[0];
    int cur_jump = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (i > cur_jump)
        return false;
      max_jump = max(max_jump, i + nums[i]);
      if (cur_jump == i) {
        cur_jump = max_jump;
      }
    }
    return true;
  }
};

int main() {}
