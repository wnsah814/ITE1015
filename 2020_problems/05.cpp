#include <iostream>
using namespace std;

class Test {
  public:
    Test(int a, int b) {}
    Test(int a) {}
    Test(char c) {}
    ~Test() {}
};

int main() {
  Test test1(1,2);
  // Test test2;
  Test test3(3);
  // Test test4("a");
}