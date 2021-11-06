#include <iostream>
#include "shapes.h"
using namespace std;

int main() {
    while(true) {
        cout << "\nshape?\n";
        char s;
        cin >> s;
        if (s == 'C') {
            int x,y,r;
            cin >> x >> y >> r;
            Circle cir = Circle(x, y, r);
            cout << "area: " << cir.area() << ", ";
            cout << "perimeter: " << cir.perimeter() << endl;
        } else if (s == 'R') {
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Retangle ret = Retangle(x1, y1, x2, y2);
            cout << "area: " << ret.area() << ", ";
            cout << "perimeter: " << ret.perimeter() << endl;
        } else if (s == 'Q'){
            break;
        }
    }
}