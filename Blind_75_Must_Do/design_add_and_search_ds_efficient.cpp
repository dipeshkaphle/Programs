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
};

class WordDictionary {
public:
  vector<Node> nodes;
  int ptr;
  unordered_set<string> matches;
  unordered_set<string> prefixes;
  /** Initialize your data structure here. */
  WordDictionary() : ptr(2) { nodes.assign(2, Node()); }

  void addWord(string word) {
    int cur = 1;
    for (char c : word) {
      if (!nodes[cur].mp.count(c)) {
        nodes[cur].mp[c] = ptr++;
        nodes.emplace_back();
      }
      cur = nodes[cur].mp[c];
    }
    nodes[cur].is_end = true;
  }
  bool hasWord(string &word) {
    int cur = 1;
    for (char c : word) {
      if (!nodes[cur].mp.count(c)) {
        return false;
      }
      cur = nodes[cur].mp[c];
    }
    return nodes[cur].is_end;
  }

  bool isPrefix(string &word) {
    int cur = 1;
    for (char c : word) {
      if (!nodes[cur].mp.count(c)) {
        return false;
      }
      cur = nodes[cur].mp[c];
    }
    return true;
  }
  bool search2(string &word, int i, int cur) {
    if (i >= word.size()) {
      return nodes[cur].is_end;
    }
    if (word[i] == '.') {
      for (auto [c, ind] : nodes[cur].mp) {
        if (search2(word, i + 1, ind)) {
          return true;
        }
      }
      return false;
    } else {
      if (nodes[cur].mp.count(word[i])) {
        return search2(word, i + 1, nodes[cur].mp[word[i]]);
      } else {
        return false;
      }
    }
  }
  bool search(string word) { return search2(word, 0, 1); }
};

int main() {}
