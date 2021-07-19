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
const int NUM_OF_PHIL = 5;

sem_t sems[NUM_OF_PHIL];
int left(int p) { return p; }
int right(int p) { return (p + 1) % NUM_OF_PHIL; }

void think(int p) {
  cout << "P" << p << " is thinking\n";
  this_thread::sleep_for(1000ms);
}
void eat(int p) { cout << "P" << p << " ate\n"; }

void get_forks(int p) {
  /*
   * If everyone tries to get left one and then right one
   * we'll be deadlocked
   * SO to make sure that never happens just make one of the
   * philosophers grab the forks in reverse order
   */
  if (p == 0) {
    sem_wait(&sems[right(p)]);
    sem_wait(&sems[left(p)]);
  } else {
    sem_wait(&sems[left(p)]);
    sem_wait(&sems[right(p)]);
  }
}
void put_forks(int p) {
  sem_post(&sems[right(p)]);
  sem_post(&sems[left(p)]);
}

void work(int p) {
  for (int i = 0; i < 5; i++) {
    think(p);
    get_forks(p);
    eat(p);
    put_forks(p);
  }
}

int main() {
  for (int i = 0; i < NUM_OF_PHIL; i++)
    sem_init(&sems[i], 0, 1);
  thread t1(work, 0);
  thread t2(work, 1);
  thread t3(work, 2);
  thread t4(work, 3);
  thread t5(work, 4);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
}
