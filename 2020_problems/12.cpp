#include <iostream>
using namespace std;

void f1(int x) { x++; }
void f2(int& x) { x++; }

int main() {
  int p = 65;
  int q = 65;
  f1(p);
  f2(q);
  cout << p << ' ' << q << endl;
  return 0;
}