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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *merge(ListNode *l1, ListNode *l2) {
    if (!l1 && !l2) {
      return nullptr;
    }
    if (!l1 || !l2) {
      return l1 ? l1 : l2;
    }
    if (l1->val < l2->val) {
      l1->next = merge(l1->next, l2);
      return l1;
    } else {
      l2->next = merge(l1, l2->next);
      return l2;
    }
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return nullptr;
    int n = lists.size();
    for (int len = 1; len < n; len *= 2) {
      for (int j = 0; (j + len) < n; j += (len * 2)) {
        lists[j] = merge(lists[j], lists[j + len]);
      }
    }
    return lists[0];
  }
};

int main() {}
