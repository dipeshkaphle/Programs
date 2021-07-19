#include <algorithm>
#include <condition_variable>
#include <iostream>
#include <iterator>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <semaphore.h>
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
// std::mutex mt;
// std::condition_variable empt, full;

sem_t empt, full;
void producer() {
  for (int i = 0; i < 1000000; i++) {
    sem_wait(&empt);
    // need ok from consumer
    items = 1;
    // cout << "Producer: " << items << endl;
    sem_post(&full);
  }
}
void consumer(const string &name) {
  for (int i = 0; i < 500000; i++) {
    sem_wait(&full);
    items = 0;
    cout << name;
    sem_post(&empt);
  }
}

int main() {
  sem_init(&empt, 0, 1);
  sem_init(&full, 0, 0);
  std::thread p(producer);
  std::thread c1(consumer, "C1");
  std::thread c2(consumer, "C2");
  p.join();
  c1.join();
  c2.join();
}
