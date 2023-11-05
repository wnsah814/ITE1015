#include <iostream>
#include <map>

using namespace std;

int main() {
  map<string, double> m;
  for (int i = 0; i < 4; ++i) {
    m.insert({"string"+to_string(i), 0.5*i});
  }
}