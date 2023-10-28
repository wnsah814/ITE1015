#include <iostream>
using namespace std;

int main() {
  int a = 10;
  int b = a;
  int* p = &a;
  int& r = a;

  a = 20;
  b = 30;

  *p = 10;
  r = 40;

  p = &b;
  *p = 50;

  cout << a << endl;
  cout << b << endl;
  cout << *p << endl;
  cout << r << endl;

  return 0;
}