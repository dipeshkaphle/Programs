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
  int rob(vector<int> &nums) {
    int rob1 = 0, rob2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      int tmp = max(rob1, rob2 + nums[i]);
      rob2 = rob1;
      rob1 = tmp;
    }
    return max(rob1, rob2);
  }
};

int main() {}
