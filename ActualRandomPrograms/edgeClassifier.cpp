#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

// edge classifier for directed graphs
using namespace std;

enum class edge_type { TREE, FORWARD, BACKWARD, CROSS, UNCLASSIFIED };
enum class status { DISCOVERED, UNDISCOVERED, PROCESSED };

void dfs(int node_id, const vector<vector<int>> &adj,
         vector<pair<status, size_t>> &state,
         vector<vector<edge_type>> &types) {
  static size_t time = 0;
  state[node_id].second = time++;
  state[node_id].first = status::DISCOVERED;
  for (int x : adj[node_id]) {
    if (state[x].first == status::DISCOVERED) {
      types[node_id][x] = edge_type::BACKWARD;
    } else if (state[x].first == status::PROCESSED) {
      if (state[x].second < state[node_id].second) {
        types[node_id][x] = edge_type::CROSS;
      } else {
        types[node_id][x] = edge_type::FORWARD;
      }
    } else {
      types[node_id][x] = edge_type::TREE;
      dfs(x, adj, state, types);
    }
  }
  state[node_id].first = status::PROCESSED;
}

void dfs_all(const vector<vector<int>> &adj) {
  vector<vector<edge_type>> types(
      adj.size(), vector<edge_type>(adj.size(), edge_type::UNCLASSIFIED));
  for (int i = 0; i < adj.size(); i++) {
    vector<pair<status, size_t>> state(adj.size(), {status::UNDISCOVERED, 0});
    dfs(i, adj, state, types);
  }
}

int main() {
  vector<vector<int>> adj = {{1, 3, 2}, {2, 0}, {0}, {1}};
  vector<vector<edge_type>> types(
      adj.size(), vector<edge_type>(adj.size(), edge_type::UNCLASSIFIED));
  vector<pair<status, size_t>> state(adj.size(), {status::UNDISCOVERED, 0});
  dfs(0, adj, state, types);
  cout << "OK\n";
}
