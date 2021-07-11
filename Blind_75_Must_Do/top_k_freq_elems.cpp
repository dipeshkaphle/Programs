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
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> cnt;
    for (int i = 0; i < nums.size(); i++)
      cnt[nums[i]]++;
    vector<pair<int, int>> vec;
    for (auto &x : cnt)
      vec.push_back({x.second, x.first});
    priority_queue<pair<int, int>> pq;
    int n = vec.size();
    vector<int> ans;
    for (auto &x : vec) {
      pq.push(x);
      if (n - pq.size() < k) {
        ans.push_back(pq.top().second);
        pq.pop();
      }
    }
    return ans;
  }
};

int main() {}
