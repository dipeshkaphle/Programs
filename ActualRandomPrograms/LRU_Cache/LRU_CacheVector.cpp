#include "LRU_Cache.h"
#include <algorithm>

template <typename T> access_status LRU_Cache<T>::access(const T &key) {
  if (keys.contains(key)) {
    auto index = keys[key];
    this->update(index);
    return HIT;
  } else {
    if (cache.size() == this->max_size) {
      this->update(0);
      keys.erase(cache.back());
      cache.back() = key;
      keys[cache.back()] = cache.size() - 1;
    } else {
      cache.emplace_back(key);
      keys[cache.back()] = cache.size() - 1;
    }
  }
  return MISS;
}

template <typename T> access_status LRU_Cache<T>::access(T &&key) {
  T x = key;
  return this->access(x);
}

template <typename T> void LRU_Cache<T>::print_cache() {
  std::cout << "Cache: {\n";
  std::for_each(cache.begin(), cache.end(), [i = 0](auto &x) mutable {
    std::cout << x << ": " << i++ << "\n";
  });
  std::cout << "}\n";
}

template <typename T> std::optional<T> LRU_Cache<T>::least_recently_used() {
  if (this->cache.size() > 0) {
    return std::make_optional<T>(this->cache[0]);
  } else
    return std::make_optional<T>();
}

template <typename T> std::optional<T> LRU_Cache<T>::most_recently_used() {
  if (this->cache.size() > 0) {
    return std::make_optional<T>(this->cache.back());
  } else
    return std::make_optional<T>();
}

template <typename T> void LRU_Cache<T>::update(size_t index) {
  auto cur_key = std::move(cache[index]);
  keys[cur_key] = cache.size() - 1;
  for (auto i = index; i < cache.size() - 1; i++) {
    keys[cache[i + 1]]--;
    cache[i] = std::move(cache[i + 1]);
  }
  cache.back() = std::move(cur_key);
}
