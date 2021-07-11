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
  bool contains(unordered_map<char, int> &s_mp,
                unordered_map<char, int> &t_mp) {
    for (auto [c, cnt] : t_mp) {
      if (s_mp[c] < cnt)
        return false;
    }
    return true;
  }
  string minWindow(string s, string t) {
    unordered_map<char, int> s_mp, t_mp;
    for (char c : t)
      t_mp[c]++;
    int j = 0, n = s.size();
    while (j < n && !contains(s_mp, t_mp)) {
      s_mp[s[j++]]++;
    }
    if (!contains(s_mp, t_mp))
      return "";
    j--;
    bool has_ = true;
    int min_ = j + 1;
    int strt = 0;
    int i = 0;
    while (j < n) {
      s_mp[s[i]]--;
      if (s_mp[s[i]] < t_mp[s[i]]) {
        j++;
        while (j < n && s[j] != s[i]) {
          s_mp[s[j++]]++;
        }
        if (j == n)
          break;
        s_mp[s[j]]++;
      }
      i++;
      if (j - i + 1 < min_) {
        min_ = j - i + 1;
        strt = i;
      }
    }
    return s.substr(strt, min_);
  }
};

int main() {}
