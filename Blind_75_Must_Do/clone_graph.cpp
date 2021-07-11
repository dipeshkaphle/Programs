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
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  unordered_map<Node *, Node *> vis;
  Node *helper(Node *node) {
    if (!node)
      return nullptr;
    if (vis.count(node)) {
      return vis[node];
    }
    Node *eqv = new Node(node->val);
    vis[node] = eqv;
    vector<Node *> neigh = node->neighbors;
    for (auto &x : neigh) {
      x = helper(x);
    }
    eqv->neighbors = neigh;
    return eqv;
  }
  Node *cloneGraph(Node *node) {
    vis.clear();
    return helper(node);
  }
};

int main() {}
