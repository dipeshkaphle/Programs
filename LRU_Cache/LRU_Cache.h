#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <optional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
enum access_status { HIT, MISS };

template <typename T> class LRU_Cache {
public:
  LRU_Cache() = delete;
  LRU_Cache(size_t cache_size) : max_size(cache_size) {}
  access_status access(T &&key);
  access_status access(const T &key);
  void print_cache();
  std::optional<T> least_recently_used();
  std::optional<T> most_recently_used();

private:
  void update(size_t index);
  std::vector<T> cache;
  std::unordered_map<T, size_t> keys;
  size_t max_size;
};

#include "LRU_Cache.cpp"
#endif // LRU_CACHE_H
