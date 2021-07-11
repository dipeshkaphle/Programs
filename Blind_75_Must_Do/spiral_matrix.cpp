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
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix.front().size();
    vector<vector<bool>> seen(m, vector<bool>(n, false));
    int r = 0, c = 0;
    vector<int> dr{0, 1, 0, -1};
    vector<int> dc{1, 0, -1, 0};
    int delta = 0;
    for (int i = 0; i < m * n; i++) {
      ans.push_back(matrix[r][c]);
      seen[r][c] = true;
      int next_r = r + (dr[delta]);
      int next_c = c + (dc[delta]);
      if (next_c >= 0 && next_c < n && next_r >= 0 && next_r < m &&
          !seen[next_r][next_c]) {
        r = next_r;
        c = next_c;
      } else {
        delta = (delta + 1) % 4;
        r += (dr[delta]);
        c += (dc[delta]);
      }
    }
    return ans;
  }
};

int main() {}
