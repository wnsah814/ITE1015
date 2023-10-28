#include <iostream>
#include <string>
using namespace std;

void f() {
  throw string("error occured");
  return;
}

int main() {
  try {
    f();
  } catch (...) {
    cout << "caught an err!\n";
  }
  return 0;
}