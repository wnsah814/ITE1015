#include <iostream>

class Vector {
  public:
    int * x;
    int size;

    Vector() : x(NULL), size(0) {}
    Vector(int n) {
      size = n;
      x = new int [size];
    }

    ~Vector() {
      delete[] x;
    }

    void Resize(int n) {
      delete[] x;
      x = new int[size = n];
    }
};

int main() {
  Vector *p = new Vector(10);
  for (int j = 0; j < p -> size; ++j) {
    p -> x[j] = j;
  }

  Vector *q = new Vector[10];
  for (int i = 0; i < 10; ++i) {
    q[i].Resize(i);
  }
}