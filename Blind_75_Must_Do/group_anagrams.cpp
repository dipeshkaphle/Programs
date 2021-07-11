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
/*
 * not a good solution
 * use rolling hash
 */
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> dict;
    string tmp;
    for (string x : strs) {
      tmp = x;
      sort(tmp.begin(), tmp.end());
      dict[tmp].push_back(x);
    }
    vector<vector<string>> result;
    for (auto x : dict)
      result.push_back(x.second);
    return result;
  }
};

int main() {}
