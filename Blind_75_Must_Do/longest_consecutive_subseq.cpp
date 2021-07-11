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
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    if (nums.empty())
      return 0;
    int max_ = 0;
    for (int x : nums) {
      if (!st.count(x - 1)) {
        int cnt = 1;
        int elem = x;
        while (st.count(elem + 1)) {
          elem++;
          cnt++;
        }
        max_ = max(max_, cnt);
      }
    }
    return max_;
  }
};

int main() {}
