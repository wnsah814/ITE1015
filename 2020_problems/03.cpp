#include <iostream>
using namespace std;

class Base {
public:
  void f() {
    cout << "Base\n";
  }
};

class Derived : public Base {
public:
  void f() {
    cout << "Derived\n";
  }
};

int main() {
  Base *p = new Derived();
  p -> f();
  return 0;
}