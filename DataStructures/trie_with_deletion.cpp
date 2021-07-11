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

int main() {
  Trie t;
  Vec<string> words{"oa", "oaa", "abc", "abcd"};
  for (auto &x : words) {
    t.insert(x);
  }
  t.del(words[1]);
  cout << t.exists(words[1]) << '\n';
  cout << t.exists(words[0]) << "\n";
  t.del(words.back());
  cout << t.exists(words.back()) << "\n";
}
