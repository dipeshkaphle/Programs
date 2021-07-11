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
  vector<int> dx = {-1, 1, 0, 0};
  vector<int> dy = {0, 0, -1, 1};
  vector<vector<bool>> visited;
  int m, n, cnt;
  void dfs(int i, int j, vector<vector<char>> &grid) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1' &&
          !visited[x][y])
        dfs(x, y, grid);
    }
  }

  int numIslands(vector<vector<char>> &grid) {
    m = grid.size();
    n = grid.front().size();
    cnt = 0;
    visited.assign(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          cnt++;
          dfs(i, j, grid);
        }
      }
    }
    return cnt;
  }
};

int main() {}
