#include <iostream>
#include <vector>

using namespace std;

class A {
public:
    virtual string getTypeInfo() {
        return "This is an instance of class A";
    }
};

class B: public A {
public:
    string getTypeInfo() {
        return "This is an instance of class B";
    }
};

class C: public B {
public:
    string getTypeInfo() {
        return "This is an instance of class C";
    }
};

void printObjectTypeInfo1(A* object) {
    cout << object -> getTypeInfo() << endl;
}

void printObjectTypeInfo2(A& object) {
    cout << object.getTypeInfo() << endl;
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