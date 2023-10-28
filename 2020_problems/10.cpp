#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int* num = new int;
  int* numArr = new int[n];

  *num = n;
  for (int i = 0; i < n; ++i) {
    numArr[i] = i;
  }

  cout << *num << endl;
  for (int i = 0; i < n; ++i) {
    cout << numArr[i] << " ";
  }
  cout << endl;

  delete num;
  delete[] numArr;

  return 0;
}