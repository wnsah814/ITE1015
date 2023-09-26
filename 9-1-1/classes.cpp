#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    virtual ~A() {}
    virtual string test() {
        return "A::test()";
    }
};

class B : public A {
public: 
    ~B() {}
    string test() {
        return "B::test()";
    }
};

class C: public B {
public:
    ~C() {}
    string test() {
        return "C::test()";
    }
};

int main() {
    vector<A*> v;
    v.push_back(new A);
    v.push_back(new B);
    v.push_back(new C);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] -> test() << endl;
    }
    for (int i = 0; i < v.size(); i++) {
        delete v[i];
    }

    return 0;
}