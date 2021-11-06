#include <iostream>
#include <vector>
#include <string>
#include "intset.h"
using namespace std;

int main() {
    IntegerSet is;
    string command;
    cin >> command;
    int n;
    while (command != "quit") {
        cin >> n;
        if (command == "add") {
            is.AddNumber(n);
        } else if (command == "get") {
            cout << is.GetItem(n) << endl;
        } else if (command == "del") {
            is.DeleteNumber(n);
        }
        cin >> command;
    }
    return 0;
}