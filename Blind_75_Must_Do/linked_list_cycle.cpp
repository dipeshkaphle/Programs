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
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  bool hasCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
};

int main() {}
