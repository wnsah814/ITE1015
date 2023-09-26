#include <iostream>
#include <string>
#include "my_container.h"

using namespace std;

int main() {
    int len;
    
    cin >> len;
    MyContainer<int> con1(len);
    cin >> con1;
    cout << con1 << endl;

    cin >> len;
    MyContainer<double> con2(len);
    cin >> con2;
    cout << con2 << endl;

    cin >> len;
    MyContainer<string> con3(len);
    cin >> con3;
    cout << con3 << endl;
    
    return 0;
}