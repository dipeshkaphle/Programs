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

unordered_map<string, int> out_deg;
unordered_map<string, int> in_deg;
unordered_map<string, vector<string>> adj;
vector<string> ans;
void dfs(string &st) {
  for (; out_deg[st] != 0;) {
    out_deg[st]--;
    dfs(adj[st][out_deg[st]]);
  }
  ans.push_back(st);
}
vector<string> solve(vector<vector<string>> &flights) {
  ans.clear();
  adj.clear();
  in_deg.clear();
  out_deg.clear();
  for (auto &x : flights) {
    adj[x[0]].push_back(x[1]);
    adj[x[1]];
    in_deg[x[0]];
    out_deg[x[1]];
    in_deg[x[1]]++;
    out_deg[x[0]]++;
  }
  vector<string> nodes;
  for (auto &[x, _] : adj) {
    nodes.push_back(x);
  }
  for (auto &[key, nodes] : adj) {
    sort(nodes.begin(), nodes.end(), greater<string>());
  }
  sort(nodes.begin(), nodes.end());
  string start = "";
  for (auto &x : nodes) {
    if (out_deg[x] - in_deg[x] == 1) {
      start = x;
      break;
    }
  }
  if (start.empty())
    start = nodes[0];
  dfs(start);
  reverse(ans.begin(), ans.end());
  return ans;
}
int main() {}
