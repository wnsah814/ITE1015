#include <iostream>
#include <string>
#include "my_vector2.h"

using namespace std;

int main() {
    string s1, s2, op;
    MyVector2 *a = nullptr, *b = nullptr;
    int len;
    while (true) {
        cin >> s1;
        if (s1 == "new") {
            cin >> len;
            a = new MyVector2(len);
            cout << "enter a\n";
            cin >> *a;
            b = new MyVector2(len);
            cout << "enter b\n";
            cin >> *b;
        } else if (s1 == "quit") {
            break;
        } else if (s1 == "a") {
            cin >> op >> s2;
            if (op == "+") {
                if (s2 == "a") {
                    MyVector2 tmp(*a + *a);
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    MyVector2 tmp(*a + *b);
                    cout << tmp << endl;
                } else {
                    MyVector2 tmp(*a + stoi(s2));
                    cout << tmp << endl;
                }
            } else if (op == "-") {
                if (s2 == "a") {
                    MyVector2 tmp(*a - *a);
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    MyVector2 tmp(*a - *b);
                    cout << tmp << endl;
                } else {
                    MyVector2 tmp(*a - stoi(s2));
                    cout << tmp << endl;
                }
            }
        } else if (s1 == "b") {
            cin >> op >> s2;
            if (op == "+") {
                if (s2 == "a") {
                    MyVector2 tmp(*b + *a);
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    MyVector2 tmp(*b + *b);
                    cout << tmp << endl;
                } else {
                    MyVector2 tmp(*b + stoi(s2));
                    cout << tmp << endl;
                }
            } else if (op == "-") {
                if (s2 == "a") {
                    MyVector2 tmp(*b - *a);
                    cout << tmp << endl;
                } else if (s2 == "b") {
                    MyVector2 tmp(*b - *a);
                    cout << tmp << endl;
                } else {
                    MyVector2 tmp(*b + stoi(s2));
                    cout << tmp << endl;
                }
            }
        }
    }
    return 0;
}