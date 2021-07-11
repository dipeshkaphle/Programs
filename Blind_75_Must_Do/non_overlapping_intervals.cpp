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
  // basically the merge intervals problem
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> st;
    st.push_back(intervals.front());
    int cnt = 0;
    for (int i = 1; i < intervals.size(); i++) {
      auto &last = st.back();
      auto &cur = intervals[i];
      if (cur[0] < last[1]) {
        last[0] = min(cur[0], last[0]);
        last[1] = min(cur[1], last[1]);
        cnt++;
      } else {
        st.push_back(cur);
      }
    }
    return cnt;
  }
};

int main() {
  Solution s;
  Vec<Vec<i32>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  s.eraseOverlapIntervals(intervals);
}
