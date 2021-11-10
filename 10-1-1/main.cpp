#include <iostream>
#include <vector>
#include "shape.h"

using namespace std;

int main() {
  vector<Shape*> arr;
  char command;
  cin >> command;
  while (command != '0') {
    int width, height;
    if (command == 'r') {
      cin >> width >> height;
      arr.push_back(new Rectangle(width, height));
    } else if (command == 't') {
      cin >> width >> height;
      arr.push_back(new Triangle(width, height));
    }
    cin >> command;
  }

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] -> getArea() << endl;
  }

  for (int i = 0; i < arr.size(); i++) {
    delete arr[i];
  }
  return 0;
}
