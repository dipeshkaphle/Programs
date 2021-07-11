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
  int m;
  int n;
  void dfs(int i, int j, vector<vector<int>> &heights,
           vector<vector<bool>> &vis) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (x >= 0 && y >= 0 && x < m && y < n &&
          heights[x][y] >= heights[i][j] && !vis[x][y])
        dfs(x, y, heights, vis);
    }
  }
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    m = heights.size();
    n = heights.front().size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    auto atlantic = pacific;
    vector<vector<int>> ans;
    for (int i = 0; i < m; i++) {
      dfs(i, 0, heights, pacific);
      dfs(i, n - 1, heights, atlantic);
    }
    for (int i = 0; i < n; i++) {
      dfs(0, i, heights, pacific);
      dfs(m - 1, i, heights, atlantic);
    }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (pacific[i][j] && atlantic[i][j])
          ans.push_back({i, j});
    return ans;
  }
};

int main() {}
