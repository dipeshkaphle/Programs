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
  int findMin(vector<int> &nums) {
    int l = -1;
    int r = nums.size() - 1;
    int lft = nums.front() - 1;
    int rt = nums.back();
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (nums[mid] > rt) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return nums[l + 1];
  }
};

int main() {}
