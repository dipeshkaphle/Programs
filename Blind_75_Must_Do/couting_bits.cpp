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
  vector<int> countBits(int n) {
    /*
     * To find for any number n
     * We make an array of 256 following this procedure
     * Then we do arr[x&0xff] + arr[(x>>8)&0xff] + arr[(x>>16)&0xff] +
     * arr[(x>>24)&0xff]
     */
    vector<int> arr(n + 1);
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
      arr[i] = i & 1;
      arr[i] += arr[i / 2];
    }
    return arr;
  }
};
int main() {}
