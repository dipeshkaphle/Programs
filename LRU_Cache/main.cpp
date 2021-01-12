#include "LRU_Cache.h"
#include <cstddef>
#include <iostream>
#include <string>

int main() {
  std::cout << "Hello"
            << "\n";
  LRU_Cache<int> cache(static_cast<size_t>(4));
  cache.access(1);
  cache.access(2);
  cache.access(3);
  cache.print_cache();
  cache.access(2);
  cache.print_cache();
  cache.access(4);
  cache.print_cache();
  cache.access(1);
  cache.print_cache();
  cache.access(5);
  cache.print_cache();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  auto a = cache.least_recently_used();
  if (a.has_value())
    std::cout << a.value() << std::endl;
  int z = 10;
  cache.access(z);
  cache.print_cache();
}
