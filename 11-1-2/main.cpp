#include <iostream>
#include <string>
#include "my_string2.h"
using namespace std;
int main() {
    string s1, s2, op;
    MyString2 a, b;
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
                MyString2 tmp(a * stoi(s2));
                cout << tmp << endl;
            } else if (op == "+") {
                if (s2 == "a") {
                    MyString2 tmp(a + a);
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    MyString2 tmp(a + b);
                    cout << tmp << endl;
                }
            }
        } else if (s1== "b") {
            cin >> op >> s2;
            if (op == "*") {
                MyString2 tmp(b * stoi(s2));
                cout << tmp << endl;
            } else if (op == "+") {
                if (s2 == "a") {
                    MyString2 tmp(b + a);
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    MyString2 tmp(b + b);
                    cout << tmp << endl;
                }
            }
        }
    }
    return 0;
}