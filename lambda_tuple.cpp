#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

template <typename T> struct element_wrapper { T val; };

template <typename... Args> auto make_tuple(Args &&...args) {
  return [... args = element_wrapper<Args>{std::forward<Args>(args)}](
             auto &&fn) mutable -> decltype(auto) { return fn(args.val...); };
}

auto printer = [](auto &&...args) { ((std::cout << args << ' '), ...); };

template <typename Self, typename Fn>
decltype(auto) apply_func(Self &&self, Fn &&fn) {
  return self.data(fn);
}

template <std::size_t ind, typename Head, typename... Tail>
decltype(auto) tuple_get(Head &&head, Tail &&...tail) {
  if constexpr (ind == 0)
    return decltype(head)(head);
  else
    return tuple_get<ind - 1>(decltype(tail)(tail)...);
}

template <std::size_t N, typename WantedType, typename Head, typename... Tail>
constexpr std::size_t get_index_of_type() {
  if constexpr (std::is_same_v<WantedType, Head>)
    return N;
  else
    return get_index_of_type<N + 1, WantedType, Tail...>();
}

template <typename... Ts> class Tuple {
public:
  Tuple() requires((std::is_default_constructible_v<Ts> && ...))
      : data(make_tuple<Ts...>(Ts{}...)) {}

  template <typename... Args>
  Tuple(Args &&...args)
      : data(make_tuple<Ts...>((std::forward<Ts>(args))...)) {}

  template <typename Self, typename Fn>
  decltype(auto) friend apply_func(Self &&, Fn &&);

  template <typename T> decltype(auto) get() {
    return this->get<get_index_of_type<0, T, Ts...>()>();
  }

  template <std::size_t N> decltype(auto) get() {
    return apply_func(*this, [](auto &&...args) -> decltype(auto) {
      return tuple_get<N>(std::forward<decltype(args)>(args)...);
    });
  }

  // private:
  decltype(make_tuple<Ts...>(std::declval<Ts>()...)) data;
};

int main() {
  auto tpl = make_tuple(1, 2, 3, 4.2, "HI");
  tpl(printer);
  std::cout << '\n';
  int a = 10;
  float b = 2.5;
  Tuple<int, int &, float> tup(a, a, b);
  apply_func(tup, printer);
  std::cout << '\n';
  tup.get<1>() = 11;
  std::cout << a << '\n';
  std::cout << '\n';
}
