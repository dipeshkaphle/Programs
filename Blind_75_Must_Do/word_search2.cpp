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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
struct Node {
  bool is_end = false;
  unordered_map<char, int> mp;
  int cnt = 0;
  Node() : is_end(false), cnt(0) {}
};
struct Trie {
  vector<Node> nodes;
  int ptr;
  Trie() {
    nodes.assign(2, Node());
    ptr = 2;
  }
  void insert(string &s) {
    int cur = 1;
    for (char c : s) {
      if (!nodes[cur].mp.count(c)) {
        nodes[cur].mp[c] = ptr++;
        nodes.emplace_back();
      }
      nodes[cur].cnt++;
      cur = nodes[cur].mp[c];
    }
    nodes[cur].is_end = true;
  }
  bool exists(string &s) {
    int cur = 1;
    for (char c : s) {
      if (nodes[cur].cnt == 0) {
        return false;
      }
      if (!nodes[cur].mp.count(c)) {
        return false;
      }
      cur = nodes[cur].mp[c];
    }
    return nodes[cur].is_end;
  }
  bool prefix_exists(string &s) {
    int cur = 1;
    for (char c : s) {
      if (!nodes[cur].mp.count(c)) {
        return false;
      }
      cur = nodes[cur].mp[c];
      if (nodes[cur].cnt == 0) {
        return false;
      }
    }
    return true;
  }
  void del(string &s) {
    int cur = 1;
    if (!exists(s)) {
      return;
    }
    for (char c : s) {
      nodes[cur].cnt--;
      cur = nodes[cur].mp[c];
    }
    nodes[cur].is_end = false;
  }
};
class Solution {
public:
  vector<vector<bool>> vis;
  unordered_set<string> found;
  int m;
  int n;
  void dfs(int i, int j, vector<vector<char>> &board, string &cur_s, Trie &tr) {
    /*
     * question states that the length of word cant be more than 10
     */
    if (cur_s.size() > 10) {
      return;
    }
    if (tr.exists(cur_s)) {
      cout << cur_s << " ";
      found.insert(cur_s);
      tr.del(cur_s);
    }
    if (!tr.prefix_exists(cur_s)) {
      return;
    }
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int x = dx[k] + i;
      int y = dy[k] + j;
      if (x >= 0 && y >= 0 && x < m && y < n && !vis[x][y]) {
        cur_s.push_back(board[x][y]);
        dfs(x, y, board, cur_s, tr);
        cur_s.pop_back();
      }
    }
    vis[i][j] = false;
  }
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    Trie t;
    found.clear();
    m = board.size();
    n = board.front().size();
    vis = vector<vector<bool>>(m, vector<bool>(n, false));
    string cur_s;
    vector<string> ans;
    for (auto &s : words)
      t.insert(s);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        cur_s += board[i][j];
        dfs(i, j, board, cur_s, t);
        cur_s.pop_back();
      }
    return vector<string>(found.begin(), found.end());
  }
};

int main() {
  Solution s;
  vector<vector<char>> board{{'o', 'a', 'b', 'n'},
                             {'o', 't', 'a', 'e'},
                             {'a', 'h', 'k', 'r'},
                             {'a', 'f', 'l', 'v'}};
  vector<string> words = {"oa", "oaa"};
  s.findWords(board, words);
}
