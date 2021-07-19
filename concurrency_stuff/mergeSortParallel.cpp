#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

void mergeSortNormal(vector<int> &vec, int l, int r) {
  if (r - l == 1) {
    return;
  }
  int m = (l + r) / 2;
  mergeSortNormal(vec, l, m);
  mergeSortNormal(vec, m, r);
  inplace_merge(vec.begin() + l, vec.begin() + m, vec.begin() + r);
}

void mergeSort(vector<int> &vec, int l, int r) {
  int m = (l + r) / 2;
  if (r - l <= 1000000) {
    mergeSortNormal(vec, l, r);
    return;
  }
  std::thread thrd1(mergeSort, std::ref(vec), l, m);
  std::thread thrd2(mergeSort, std::ref(vec), m, r);
  thrd1.join();
  thrd2.join();
  inplace_merge(vec.begin() + l, vec.begin() + m, vec.begin() + r);
}

int main() {
  vector<int> arr(100000000, 100000000);
  for (int i = 1; i < arr.size(); i++) {
    arr[i] = arr[i - 1] - 1;
  }

  auto start_time = chrono::steady_clock::now();
  mergeSort(arr, 0, arr.size());
  // mergeSortNormal(arr, 0, arr.size());
  auto end_time = chrono::steady_clock::now();
  auto elapsed_time =
      chrono::duration_cast<chrono::duration<double>>(end_time - start_time);
  cout << fixed << setprecision(30) << elapsed_time.count() << '\n';
  // copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
}
