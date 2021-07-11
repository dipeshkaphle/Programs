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
  void setZeroes(vector<vector<int>> &matrix) {
    bool zero_col = 1;
    int m = matrix.size();
    int n = matrix.front().size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          if (j == 0) {
            zero_col = 0;
          } else {
            matrix[0][j] = 0;
          }
          matrix[i][0] = 0;
        }
      }
    }
    for (int i = 1; i < m; i++) {
      if (!matrix[i][0])
        for (int j = 0; j < n; j++)
          matrix[i][j] = 0;
    }
    for (int i = 1; i < n; i++) {
      if (!matrix[0][i])
        for (int j = 0; j < m; j++)
          matrix[j][i] = 0;
    }
    if (!matrix[0][0])
      for (int j = 0; j < n; j++)
        matrix[0][j] = 0;
    if (!zero_col)
      for (int i = 0; i < m; i++)
        matrix[i][0] = 0;
  }
};

int main() {}
