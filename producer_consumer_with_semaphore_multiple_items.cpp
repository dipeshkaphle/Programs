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

sem_t empt, full, mt;

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
    sem_wait(&empt);
    sem_wait(&mt);
    // need ok from consumer
    put(i);
    // cout << "Producer: " << items << endl;
    sem_post(&mt);
    sem_post(&full);
  }
}
void consumer(const string &name) {
  for (int i = 0; i < 5; i++) {
    sem_wait(&full);
    sem_wait(&mt);
    cout << gett() << '\n';
    sem_post(&mt);
    sem_post(&empt);
  }
}

int main() {
  sem_init(&empt, 0, MAX_SIZE);
  sem_init(&full, 0, 0);
  sem_init(&mt, 0, 1);
  std::thread p(producer);
  std::thread c1(consumer, "C1");
  std::thread c2(consumer, "C2");
  p.join();
  c1.join();
  c2.join();
}
