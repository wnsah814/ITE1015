#include <iostream>
using namespace std;

class A {
  protected:
    int memberA;
  public:
    A(int n) : memberA(n) { }
    int getMember() { return memberA; }
};

class B : public A {
  public:
    B() { }
    int getMember() { return memberA; }
};

int main() {
  A a(1);
  cout << a.getMember() << endl;

  B b;
  cout << b.getMember() << endl;

  return 0;
}