#include <iostream>
#include <vector>

using namespace std;

class A {
public:
    virtual void getTypeInfo() {
        cout << "This is an instance of class A" << endl;
    }
};

class B: public A {
public:
    void getTypeInfo() {
        cout << "This is an instance of class B" << endl;
    }
};

class C: public B {
public:
    void getTypeInfo() {
        cout << "This is an instance of class C" << endl;
    }
};

void printObjectTypeInfo1(A* object) {
    object -> getTypeInfo();
}

void printObjectTypeInfo2(A& object) {
    object.getTypeInfo();
}

int main() {
    vector<A*> v;
    v.push_back(new A);
    v.push_back(new B);
    v.push_back(new C);

    for (int i = 0; i < v.size(); i++) {
        printObjectTypeInfo1(v[i]);
        printObjectTypeInfo2(*v[i]);
    }

    for (int i = 0; i < v.size(); i++) {
        delete v[i];
    }
    return 0;
}