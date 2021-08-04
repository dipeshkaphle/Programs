#include <bitset>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
  cout << argv[1] << endl;
  string bits;
  float a = atof(argv[1]);
  double x = stod(string(argv[1]));
  int j = sizeof(a);
  cout << "Float Representation: \n";
  for (int i = (j - 1); i >= 0; i--) {
    char tmp = *(((char *)&a) + i);
    bitset<8> str(tmp);
    bits = bits + str.to_string();
  }
  cout << "Sign Bit: " << bits[0] << endl;
  cout << "Exp bits: " << bits.substr(1, 8) << endl;
  cout << "Remaining bits: " << bits.substr(9) << endl;
  cout << endl;
  cout << "Double Representation: \n";
  j = sizeof(double);
  bits = "";
  for (int i = (j - 1); i >= 0; i--) {
    char tmp = *(((char *)&x) + i);
    bitset<8> str(tmp);
    bits = bits + str.to_string();
  }
  cout << "Sign Bit: " << bits[0] << endl;
  cout << "Exp bits: " << bits.substr(1, 11) << endl;
  cout << "Remaining bits: " << bits.substr(12) << endl;
}
