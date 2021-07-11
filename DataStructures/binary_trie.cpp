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

// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
struct Node {
  vector<int> mp;
  Node() : mp{-1, -1} {}
};
struct Trie {
  vector<Node> nodes;
  int ptr;
  Trie() {
    ptr = 2;
    nodes.assign(2, Node());
  }
  void insert(int x) {
    int cur = 1;
    for (int i = 31; i >= 0; i--) {
      bool bit = x & ((unsigned(1)) << i);
      if (nodes[cur].mp[bit] == -1) {
        nodes[cur].mp[bit] = ptr++;
        nodes.emplace_back();
      }
      cur = nodes[cur].mp[bit];
    }
  }
  int max_xor(int x) {
    int cur = 1;
    int res = 0;
    for (int i = 31; i >= 0; i--) {
      bool bit = x & ((unsigned(1)) << i);
      if (bit) {
        if (nodes[cur].mp[0] == -1) {
          cur = nodes[cur].mp[1];
        } else {
          cur = nodes[cur].mp[0];
          res |= ((unsigned(1)) << i);
        }
      } else {
        if (nodes[cur].mp[1] == -1) {
          cur = nodes[cur].mp[0];
        } else {
          cur = nodes[cur].mp[1];
          res |= ((unsigned(1)) << i);
        }
      }
    }
    return res;
  }
};
class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    Trie t;
    for (int x : nums)
      t.insert(x);
    int max_ = 0;
    for (int x : nums)
      max_ = max(max_, t.max_xor(x));
    return max_;
  }
};
int main() {}
