#include <iostream>
#include <string>
#include "my_vector.h"

using namespace std;

int main() {
    string s1, s2, op;
    MyVector a, b, tmp;
    int len;
    while (true) {
        cin >> s1;
        if (s1 == "new") {
            cin >> len;
            a = MyVector(len);
            b = MyVector(len);
            cout << "enter a\n";
            cin >> a;
            cout << "enter b\n";
            cin >> b;
        } else if (s1 == "quit") {
            break;
        } else if (s1 == "a") {
            cin >> op >> s2;
            if (op == "+") {
                if (s2 == "a") {
                    tmp = a + a;
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    tmp = a + b;
                    cout << tmp << endl;
                } else {
                    tmp = a + stoi(s2);
                    cout << tmp << endl;
                }
            } else if (op == "-") {
                if (s2 == "a") {
                    tmp = a - a;
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    tmp = a - b;
                    cout << tmp << endl;
                } else {
                    tmp = a - stoi(s2);
                    cout << tmp << endl;
                }
            }
        } else if (s1 == "b") {
            cin >> op >> s2;
            if (op == "+") {
                if (s2 == "a") {
                    tmp = b + a;
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    tmp = b + b;
                    cout << tmp << endl;
                } else {
                    tmp = b + stoi(s2);
                    cout << tmp << endl;
                }
            } else if (op == "-") {
                if (s2 == "a") {
                    tmp = b - a;
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    tmp = b - b;
                    cout << tmp << endl;
                } else {
                    tmp = b - stoi(s2);
                    cout << tmp << endl;
                }
            }
        }
    }
    return 0;
}