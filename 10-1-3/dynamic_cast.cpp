#include <iostream>
#include <vector>
#include <string>

using namespace std;

class B {
public:
    virtual ~B() {}
};

class C: public B {
public:
    void test_C() {
        cout << "C::test_C()" << endl;
    }
};

class D: public B {
public:
    void test_D() {
        cout << "D::test_D()" << endl;
    }
};

int main() {
    string s;
    cin >> s;
    vector<B*> arr;

    while (s != "0") {
        if (s == "B") {
            arr.push_back(new B);
        } else if (s == "C") {
            arr.push_back(new C);
        } else if (s == "D") {
            arr.push_back(new D);
        }
        cin >> s;
    }

    for (int i = 0; i < arr.size(); i++) {
        C* cptr = dynamic_cast<C*>(arr[i]);
        if (cptr) {
            cptr -> test_C();
        }
        D* dptr = dynamic_cast<D*>(arr[i]);
        if (dptr) {
            dptr -> test_D();
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        delete arr[i];
    }

    return 0;
}