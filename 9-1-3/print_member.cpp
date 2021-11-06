#include <iostream>
#include <vector>
#include <string>
using namespace std;

class A {
public:
    A(int inum) {
        pint = new int;
        *pint = inum;
        cout << "new memberA" << endl; 
    }
    virtual ~A() {
        delete pint;
        cout << "delete memberA" << endl;
    }
    virtual void print() {
        cout << "*memberA " << *pint << endl;
    }
private:
    int* pint;
};

class B: public A {
public:
    B(double dnum): A(1) {
        pdouble = new double;
        *pdouble = dnum;
        cout << "new memberB" << endl;
    }
    ~B() {
        delete pdouble;
        cout << "delete memberB" << endl;
    }
    void print() {
        A::print();
        cout << "*memberB " << *pdouble << endl;
    }
private:
    double* pdouble;
};

class C: public B {
public:
    C(const string& sstring): B(1.1) {
        pstring = new string;
        *pstring = sstring;
        cout << "new memberC" << endl;
    }
    ~C() {
        delete pstring;
        cout << "delete memberC" << endl;
    }
    void print() {  
        B::print();
        cout << "*memberC " << *pstring << endl;
    }
private:
    string* pstring;
};

int main() {
    int inum;
    double dnum;
    string sstring;
    cin >> inum >> dnum >> sstring;
    vector<A*> v;
    v.push_back(new A(inum));
    v.push_back(new B(dnum));
    v.push_back(new C(sstring));
    
    for (int i = 0; i < v.size(); i++) {
        v[i] -> print();
    }
    
    for (int i = 0; i < v.size(); i++) {
        delete v[i];
    }
    return 0;
}