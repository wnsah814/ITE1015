#include <iostream>

void swap_a(int a, int b) {
  int tmp = b;
  b = a;
  a = tmp;
}

void swap_b(int *a, int *b) {
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

void swap_c(int * const a, int * const b) {
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

// void swap_d(const int *a, const int *b) {
//   int tmp = *b;
//   *b = *a;
//   *a = tmp;
// }

int main() {
  int a = 1, b = 2;
  swap_a(a, b);
  // swap_b(a, b);
  // swap_c(a, b);
  // swap_d(a, b);
  std::cout << a << ' ' << b << std::endl;
  return 0;
}