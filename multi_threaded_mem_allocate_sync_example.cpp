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

const int max_size = 4096;
int heap_used = 0;
using namespace std;
mutex mt;
condition_variable cv;
unordered_map<string, bool> alloc;

void allocate(const string &tid, int size) {
  unique_lock<mutex> lk(mt);
  cv.wait(lk, [&] { return (max_size - heap_used) >= size; });
  heap_used += size;
  alloc[tid] = true;
  cout << tid << " was allocated " << size << ",allocated=" << heap_used
       << endl;
  cv.notify_all();
}
void deallocate(const string &tid, int size) {
  unique_lock<mutex> lk(mt);
  cv.wait(lk, [&] { return alloc[tid]; });
  heap_used -= size;
  cout << tid << " has deallocated " << size << ",allocated= " << heap_used
       << endl;
  // notifies all the threads some memory is there
  cv.notify_all();
}

int main() {
  for (int i = 0; i < 1; i++) {
    thread t1(allocate, "T1", 2048);
    thread t2(allocate, "T2", 4096);
    thread t3(allocate, "T3", 2048);
    thread t4(allocate, "T4", 2048);
    thread t5(allocate, "T5", 4096);
    thread t6(allocate, "T6", 2048);
    thread t1_(deallocate, "T1", 2048);
    thread t2_(deallocate, "T2", 4096);
    thread t3_(deallocate, "T3", 2048);
    thread t4_(deallocate, "T4", 2048);
    thread t5_(deallocate, "T5", 4096);
    thread t6_(deallocate, "T6", 2048);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t1_.join();
    t2_.join();
    t3_.join();
    t4_.join();
    t5_.join();
    t6_.join();
  }
}
