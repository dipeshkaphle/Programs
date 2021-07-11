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
std::array<int, 256> arr;
bool is_init = false;
class Solution {
public:
  Solution() {
    if (!is_init) {
      is_init = true;
      arr[0] = 0;
      for (int i = 1; i < 256; i++) {
        arr[i] = (i & 1) + arr[i >> 1];
      }
    }
  }
  int hammingWeight(uint32_t n) {
    return arr[n & 0xff] + arr[(n >> 8) & 0xff] + arr[(n >> 16) & 0xff] +
           arr[(n >> 24) & 0xff];
  }
};

int main() {}
