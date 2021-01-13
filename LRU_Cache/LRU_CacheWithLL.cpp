#include "LRU_Cache.h"
#include <algorithm>

template <typename T> access_status LRU_CacheLL<T>::access(const T &key) {
  auto status = MISS;
  if (keys.contains(key)) {
    auto it = keys[key];
    cache.erase(it);
    status = HIT;
  } else {
    if (cache.size() == this->max_size) {
      keys.erase(keys.find(cache.back()));
      cache.pop_back();
    }
  }
  cache.push_front(key);
  keys[key] = cache.begin();
  return status;
}

template <typename T> access_status LRU_CacheLL<T>::access(T &&key) {
  T x = key;
  return this->access(x);
}

template <typename T> void LRU_CacheLL<T>::print_cache() {
  std::cout << "Cache: {\n";
  std::for_each(cache.begin(), cache.end(),
                [i = cache.size() - 1](auto &x) mutable {
                  std::cout << x << ": " << i-- << "\n";
                });
  std::cout << "}\n";
}

template <typename T> std::optional<T> LRU_CacheLL<T>::least_recently_used() {
  if (this->cache.size() > 0) {
    return std::make_optional<T>(cache.back());
  } else
    return std::make_optional<T>();
}

template <typename T> std::optional<T> LRU_CacheLL<T>::most_recently_used() {
  if (this->cache.size() > 0) {
    return std::make_optional<T>(cache.front());
  } else
    return std::make_optional<T>();
}
