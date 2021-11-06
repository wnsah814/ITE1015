#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    virtual ~A() {}
    virtual void test() {
        cout << "A::test()" << endl;
    }
};

class B : public A {
public: 
    ~B() {}
    void test() {
        cout << "B::test()" << endl;
    }
};

class C: public B {
public:
    ~C() {}
    void test() {
        cout << "C::test()" << endl;
    }
};

int main() {
    vector<A*> v;
    v.push_back(new A);
    v.push_back(new B);
    v.push_back(new C);

    for (int i = 0; i < v.size(); i++) {
        v[i] -> test();
    }
    for (int i = 0; i < v.size(); i++) {
        delete v[i];
    }

    return 0;
}