#include <iostream>
#include <string>
#include "my_string.h"
using namespace std;
int main() {
    string s1, s2, op;
    MyString a, b, tmp;
    while (true) {
        cin >> s1;
        if (s1== "new") {
            cout << "enter a\n";
            cin >> a;
            cout << "enter b\n";
            cin >> b;
        } else if (s1== "quit") {
            break;
        } else if (s1 == "a") {
            cin >> op >> s2;
            if (op == "*") {
                tmp = a * stoi(s2);
                cout << tmp << endl;
            } else if (op == "+") {
                if (s2 == "a") {
                    tmp = a + a;
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    tmp = a + b;
                    cout << tmp << endl;
                }
            }
        } else if (s1== "b") {
            cin >> op >> s2;
            if (op == "*") {
                tmp = b * stoi(s2);
                cout << tmp << endl;
            } else if (op == "+") {
                if (s2 == "a") {
                    tmp = b + a;
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    tmp = b + b;
                    cout << tmp << endl;
                }
            }
        }
    }
    return 0;
}