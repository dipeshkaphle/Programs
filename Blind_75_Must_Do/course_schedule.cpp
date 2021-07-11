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
  vector<bool> vis, rec_stack;
  bool has_cycle = false;
  void dfs(int src, vector<vector<int>> &graph) {
    vis[src] = true;
    rec_stack[src] = true;
    for (int x : graph[src]) {
      if (!vis[x]) {
        dfs(x, graph);
      } else if (rec_stack[x]) {
        has_cycle = true;
      }
    }
    rec_stack[src] = false;
  }
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adjList(numCourses);
    vis = vector<bool>(numCourses, false);
    rec_stack = vis;
    has_cycle = false;
    for (auto &x : prerequisites) {
      adjList[x[1]].push_back(x[0]);
    }
    for (int i = 0; i < numCourses; i++) {
      if (!vis[i]) {
        dfs(i, adjList);
        if (has_cycle)
          return false;
      }
    }
    return true;
  }
};

int main() {}
