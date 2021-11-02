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

class range {
  using ll = long long;
  ll strt;
  ll last;

public:
  range(ll l, ll r) : strt(l), last(r) {}

  struct const_iterator {
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = ll;
    using pointer = ll;
    using reference = const ll &;

    pointer m_ptr;

    const_iterator() =default;
    const_iterator(pointer ptr) : m_ptr(ptr) {}
    const_iterator(const const_iterator &iter) = default;

    reference operator*() const { return m_ptr; }

    const_iterator &operator++() {
      m_ptr++;
      return *this;
    }
    const_iterator operator++(int) {
      auto tmp = *this;
      ++(*this);
      return tmp;
    }

    const_iterator &operator--() {
      m_ptr--;
      return *this;
    }

    const_iterator operator--(int) {
      auto tmp = *this;
      --(*this);
      return tmp;
    }
    friend const_iterator operator+(const const_iterator &self,
                                    const difference_type &other) {
      return const_iterator(self.m_ptr + other);
    }
    const_iterator operator+=(const difference_type &other) {
      return *this = *this + other;
    }
    difference_type operator-(const const_iterator &other) {
      return this->m_ptr - other.m_ptr;
    }
    difference_type operator-=(const const_iterator &other) {
      return this->m_ptr - other.m_ptr;
    }

    bool operator<(const const_iterator &b) const {
      return this->m_ptr < b.m_ptr;
    }
    bool operator>(const const_iterator &b) const {
      return this->m_ptr > b.m_ptr;
    }
    friend bool operator==(const const_iterator &a, const const_iterator &b) {
      return a.m_ptr == b.m_ptr;
    }

    friend bool operator!=(const const_iterator &a, const const_iterator &b) {
      return a.m_ptr != b.m_ptr;
    }
    bool operator<=(const const_iterator &b) const {
      return this->m_ptr < b.m_ptr;
    }
    bool operator>=(const const_iterator &b) const {
      return this->m_ptr > b.m_ptr;
    }
  };

  const const_iterator cbegin() { return const_iterator(strt); }
  const const_iterator cend() { return const_iterator(last); }
  const const_iterator begin() { return const_iterator(strt); }
  const const_iterator end() { return const_iterator(last); }
};
