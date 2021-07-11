#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
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
class Trie {
public:
  /** Initialize your data structure here. */
  vector<Node> nodes;
  int ptr;
  Trie() : nodes(2) { ptr = 2; }

  /** Inserts a word into the trie. */
  void insert(string word) {
    int cur = 1;
    for (char c : word) {
      if (!nodes[cur].mp.count(c)) {
        nodes.emplace_back();
        nodes[cur].mp[c] = ptr++;
      }
      cur = nodes[cur].mp[c];
    }
    nodes[cur].is_end = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    int cur = 1;
    for (char c : word) {
      if (!nodes[cur].mp.count(c)) {
        return false;
      }
      cur = nodes[cur].mp[c];
    }
    return nodes[cur].is_end == true;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    int cur = 1;
    for (char c : prefix) {
      if (!nodes[cur].mp.count(c)) {
        return false;
      }
      cur = nodes[cur].mp[c];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  Trie trie;
  trie.insert("apple");
  trie.search("apple");   // return True
  trie.search("app");     // return False
  trie.startsWith("app"); // return True
  trie.insert("app");
  trie.search("app"); // return True
}
