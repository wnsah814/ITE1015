#include <iostream>
#include <string>

using namespace std;

template <typename T>
void myswap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {    
    int n1, n2;
    double d1, d2;
    string s1, s2;
    
    cin >> n1 >> n2;
    myswap(n1, n2);
    cout << "After calling myswap(): " << n1 << " " << n2 << endl;

    cin >> d1 >> d2;
    myswap(d1, d2);
    cout << "After calling myswap(): " << d1 << " " << d2 << endl;

    cin >> s1 >> s2;
    myswap(s1, s2);
    cout << "After calling myswap(): " << s1 << " " << s2 << endl;

    return 0;
}