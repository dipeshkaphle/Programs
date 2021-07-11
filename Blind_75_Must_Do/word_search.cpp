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
  vector<vector<bool>> vis;
  bool dfs(int i, int j, vector<vector<char>> &board, string &word, int ind) {
    if (ind == word.size())
      return true;
    vis[i][j] = true;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (x >= 0 && y >= 0 && x < m && y < n && !vis[x][y] &&
          word[ind] == board[x][y]) {
        if (dfs(x, y, board, word, ind + 1))
          return true;
      }
    }
    vis[i][j] = false;
    return false;
  }

  bool exist(vector<vector<char>> &board, string word) {
    m = board.size();
    n = board.front().size();
    vis = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (board[i][j] == word[0] && dfs(i, j, board, word, 1))
          return true;
    return false;
  }
};

int main() {}
