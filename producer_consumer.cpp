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
using namespace std;
int items = 0;
std::mutex mt;
std::condition_variable empt, full;
void producer() {
  for (int i = 0; i < 1000000; i++) {
    std::unique_lock<std::mutex> lk(mt);
    // need ok from consumer
    empt.wait(lk, []() { return items == 0; });
    items = 1;
    // cout << "Producer: " << items << endl;
    full.notify_all();
  }
}
void consumer(const string &name) {
  for (int i = 0; i < 500000; i++) {
    std::unique_lock<std::mutex> lk(mt);
    full.wait(lk, []() { return items == 1; });
    items = 0;
    cout << name;
    empt.notify_all();
  }
}

int main() {
  std::thread p(producer);
  std::thread c1(consumer, "C1");
  std::thread c2(consumer, "C2");
  p.join();
  c1.join();
  c2.join();
}
