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
  ListNode *find_mid(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  pair<ListNode *, ListNode *> rev(ListNode *head) {
    ListNode *prev = nullptr;
    auto last_node = head;
    while (head) {
      auto nxt = head->next;
      head->next = prev;
      prev = head;
      head = nxt;
    }
    return {prev, last_node};
  }
  void reorderList(ListNode *head) {
    auto mid = find_mid(head);
    auto [strt, ed] = rev(mid);
    ListNode root;
    ListNode *hd = &root;
    while ((head != ed) && strt) {
      hd->next = head;
      hd = hd->next;
      head = head->next;
      hd->next = strt;
      hd = hd->next;
      strt = strt->next;
      hd->next = nullptr;
    }
    if ((head == ed) && strt) {
      hd->next = strt;
      hd = hd->next;
      hd->next = nullptr;
      ;
    }
  }
};

int main() {}
