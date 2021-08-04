#include <bitset>
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
  int a = stoi(string(argv[1]), nullptr, 0);
  unsigned *b = (unsigned *)&a;
  float *c = (float *)&a;
  cout << "Int : " << a << endl;
  cout << "Unsigned : " << *b << endl;
  cout << "Float : " << *c << endl;
}
