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
  int getSum(int c, int d) {
    unsigned a = c;
    unsigned b = d;
    int carry = 0;
    unsigned sum = 0;
    unsigned tmp = 1;
    while (a | b | carry) {
      int x = a & 1;
      int y = b & 1;
      int ans = x ^ y ^ carry;
      carry = (x & y) | (x & carry) | (y & carry);
      a >>= 1;
      b >>= 1;
      sum |= (ans ? tmp : 0);
      tmp <<= 1;
    }
    return sum;
  }
};

int main() {}
