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

class MedianFinder {
public:
  /** initialize your data structure here. */
  priority_queue<int> l;
  priority_queue<int, vector<int>, greater<int>> r;
  MedianFinder() {}

  void addNum(int num) {
    l.push(num);
    r.push(l.top());
    l.pop();
    if (r.size() > l.size()) {
      l.push(r.top());
      r.pop();
    }
  }

  double findMedian() {
    return l.size() == r.size() ? (l.top() + r.top()) / 2.0 : l.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {}
