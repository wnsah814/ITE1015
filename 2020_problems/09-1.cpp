#include <iostream>
using namespace std;

class Base {
  private:
    int i, j;
  public:
    Base(): i(1), j(2) { }
};

class Derived : public Base {
  public:
    void show() {
      cout << "i = " << i << " j = " << j; // i, j : private
    }
};

int main(void) {
  Derived d;
  d.show();
  return 0;
}