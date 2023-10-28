#include <iostream>
#include <string>
using namespace std;

template <typename T>
void Swap(T& a, T& b) {
  cout << "Swap(T& a ,T &b) invoked" << endl;
  T tmp = b;
  b = a;
  a = tmp;
}

template <typename T>
void Swap(T* a, T* b) {
  cout << "Swap(T* a ,T* b) invoked" << endl;
  T tmp = b;
  *b = *a;
  *a = tmp;
}

int main() {
  int a = 3, b = 5;
  Swap(a, b);
  return 0;
}