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
  int to_i(string_view str) { return (str[0] - '0') * 10 + (str[1] - '0'); }
  int numDecodings(string s) {
    vector<int> cnt(s.size());
    if (s.front() == '0')
      return 0;
    cnt[0] = 1;
    int n = s.size();
    string_view str = s;
    for (int i = 1; i < s.size(); i++) {
      string_view one_len = str.substr(i, 1);
      string_view two_len = str.substr(i - 1, 2);
      if (one_len[0] != '0')
        cnt[i] += cnt[i - 1];
      if (two_len[0] != '0' && to_i(two_len) <= 26)
        cnt[i] += (i >= 2 ? cnt[i - 2] : 1);
    }
    return cnt.back();
  }
};

int main() {}
