#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <iterator>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class sema {
private:
  int count;
  std::mutex mt;
  std::condition_variable cv;

public:
  sema() : count(0) {}
  sema(int cnt) : count(cnt) {}
  sema(sema &&s) : count(s.count) {}
  sema &operator=(sema &&s) {
    count = s.count;
    return *this;
  }

  void wait() {
    std::unique_lock<std::mutex> lck(mt);
    cv.wait(lck, [&] { return count > 0; });
    count--;
  }
  void post() {
    std::unique_lock<std::mutex> lck(mt);
    count++;
    cv.notify_all();
  }
};

sema empt, full, mt;

const int MAX_SIZE = 4;
int buf[MAX_SIZE];
int used = 0;
int filled = 0;
void put(int i) {
  buf[filled] = i;
  (filled += 1) %= MAX_SIZE;
}
int gett() {
  int i = used;
  (used += 1) %= MAX_SIZE;
  return buf[i];
}

void producer() {
  for (int i = 0; i < 10; i++) {
    empt.wait();
    mt.wait();
    // need ok from consumer
    put(i);
    // cout << "Producer: " << items << endl;
    mt.post();
    full.post();
  }
}
void consumer(const std::string &name) {
  for (int i = 0; i < 5; i++) {
    full.wait();
    mt.wait();
    std::cout << gett() << '\n';
    mt.post();
    empt.post();
  }
}

int main() {
  empt = sema(MAX_SIZE);
  full = sema(0);
  mt = sema(1);
  std::thread p(producer);
  std::thread c1(consumer, "C1");
  std::thread c2(consumer, "C2");
  p.join();
  c1.join();
  c2.join();
}
