#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define UNDISCOVERED 0
#define DISCOVERED 1
#define PROCESSED 2

bool has_cycle_dfs(const vector<vector<int>> &adj, int node) {
  vector<char> state(adj.size(), UNDISCOVERED);
  vector<pair<int, size_t>> S;
  S.push_back({node, 0});
  while (!S.empty()) {
    pair<int, size_t> curr = S.back();
    if (state[curr.first] == PROCESSED) {
      S.pop_back();
      continue;
    } else if (state[curr.first] == DISCOVERED && curr.second == 0) {
      return true;
    }
    if (curr.second == 0) {
      state[curr.first] = DISCOVERED;
    }
    if (curr.second < adj[curr.first].size()) {
      S.back().second++;
      S.push_back({adj[S.back().first][S.back().second - 1], 0});
    } else {
      state[curr.first] = PROCESSED;
    }
  }
  return false;
}

bool contains_cyles(const vector<vector<int>> &adj) {
  for (int i = 0; i < adj.size(); i++) {
    if (has_cycle_dfs(adj, i)) {
      return true;
    }
  }
  return false;
}

int main() {}
