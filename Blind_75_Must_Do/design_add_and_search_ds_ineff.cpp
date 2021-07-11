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
  vector<char> get_all_after_prefix(string &word) {
    int cur = 1;
    for (char c : word) {
      if (!nodes[cur].mp.count(c)) {
        return {};
      }
      cur = nodes[cur].mp[c];
    }
    vector<char> ans;
    for (auto [c, d] : nodes[cur].mp) {
      ans.push_back(c);
    }
    return ans;
  }
  bool search2(string &new_word, string &word, int i) {
    if (i >= word.size()) {
      if (matches.count(new_word)) {
        return true;
      }
      if (hasWord(new_word)) {
        matches.insert(new_word);
        return true;
      } else {
        return false;
      }
    }
    if (!prefixes.count(new_word)) {
      if (!isPrefix(new_word)) {
        return false;
      }
      prefixes.insert(new_word);
    }
    if (word[i] == '.') {
      for (char c : get_all_after_prefix(new_word)) {
        new_word += c;
        if (search2(new_word, word, i + 1)) {
          new_word.pop_back();
          return true;
        }
        new_word.pop_back();
      }
      return false;
    } else {
      new_word += word[i];
      if (search2(new_word, word, i + 1)) {
        new_word.pop_back();
        return true;
      }
      new_word.pop_back();
      return false;
    }
  }
  bool search(string word) {
    if (matches.count(word)) {
      return true;
    }
    string s;
    if (search2(s, word, 0)) {
      matches.insert(word);
      return true;
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {}
