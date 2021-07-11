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
  int characterReplacement(string s, int k) {
    int n = s.size();
    int max_ = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
      int not_c_count = 0;
      int j = 0, i = 0;
      int max_len = 0;
      while (j < n) {
        while (j < n && not_c_count <= k) {
          not_c_count += (s[j] != c);
          j++;
        }
        if (not_c_count <= k)
          max_len = max(max_len, j - i);
        else
          max_len = max(max_len, j - i - 1);
        not_c_count -= (s[i] != c);
        i++;
      }
      max_ = max(max_, max_len);
    }
    return max_;
  }
};
/*
 * int main() {
 *   string t = "AABABBA";
 *   Solution s;
 *   s.characterReplacement(t, 1);
 * } */
