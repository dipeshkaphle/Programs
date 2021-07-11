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
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> left(nums.size() + 1);
    left[0] = 1;
    partial_sum(nums.begin(), nums.end(), left.begin() + 1, multiplies<int>());
    left.pop_back();
    int pro = nums.back();
    for (int i = nums.size() - 2; i >= 0; i--) {
      left[i] *= pro;
      pro *= nums[i];
    }
    return left;
  }
};

int main() {}
