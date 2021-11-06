#include <iostream>
#include <string>
#include "rect.h"

using namespace std;

int main() {
    string command;
    int width, height;
    cin >> command;
    while(command != "quit") {
        if (command == "nonsquare") {
            cin >> width >> height;
            NonSquare ns(width, height);
            ns.print();
        } else if (command == "square") {
            cin >> width;
            Square s(width);
            s.print();
        }
        cin >> command;
    }
    return 0;
}