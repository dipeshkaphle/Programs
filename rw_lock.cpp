#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
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
sem_t write_lock, lock;
vector<int> vec{1};
int readers = 0;

void r_lock() {
  // for mutual exclusion
  sem_wait(&lock);
  readers++;
  if (readers == 1)
    sem_wait(&write_lock);
  sem_post(&lock);
}
void r_post() {
  sem_wait(&lock);
  readers--;
  if (readers == 0)
    sem_post(&write_lock);
  sem_post(&lock);
}
void w_lock() {
  /*
   * can addd this
   * to make sure the readers++ is atomic
   * without sem_wait on lock, theres a possibility that after
   * readers++ in r_lock, it might context switch here and do
   * sem_wait on lock, if we wanted to avoid this, we can add
   * sem_wait for lock. This still never actually deadlocks
   * because if i do sem_wait here, the other one will suspend   */
  // sem_wait(&lock);
  sem_wait(&write_lock);
}
void w_post() {
  sem_post(&write_lock);
  // sem_post(&lock);
}

void read_last() {
  r_lock();
  cout << "Read: " << vec.back() << "\n";
  r_post();
}
void write_last() {
  w_lock();
  cout << "Wrote: " << (vec.size() + 1) << "\n";
  vec.push_back(vec.size() + 1);
  w_post();
}

int main() {
  // i think this is it
  sem_init(&write_lock, 0, 1);
  sem_init(&lock, 0, 1);
  for (int i = 0; i < 1000; i++) {
    thread t0(read_last);
    thread t1(write_last);
    thread t2(write_last);
    thread t3(read_last);
    thread t5(read_last);
    thread t4(write_last);
    thread t6(read_last);
    thread t7(read_last);
    thread t8(read_last);
    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
  }
}
