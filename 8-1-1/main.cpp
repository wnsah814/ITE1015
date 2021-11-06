#include <iostream>
#include <string>
#include "number.h"
using namespace std;

int main() {
    string command;
    int number;

    cin >> command;

    while (command != "quit") {
        if (command == "number") {
            cin >> number;
            Number n;
            n.setNumber(number);
            cout << "getNumber(): " << n.getNumber() << endl;
        } else if (command == "square") {
            cin >> number;
            Square s;
            s.setNumber(number);
            cout << "getNumber(): " << s.getNumber() << endl;
            cout << "getSquare(): " << s.getSquare() << endl;
        } else if (command == "cube") {
            cin >> number;
            Cube c;
            c.setNumber(number);
            cout << "getNumber(): " << c.getNumber() << endl;
            cout << "getSquare(): " << c.getSquare() << endl;
            cout << "getCube(): " << c.getCube() << endl;
        }
        cin >> command;
    }
}