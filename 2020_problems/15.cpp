#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
  return a + b;
}

int main() {
  double a = 3.1;
  int b = 5;
  cout << add(a, b) << endl;
  // compile error
  return 0;
}