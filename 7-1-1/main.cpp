#include <iostream>
#include <cstdlib>
#include <string>
#include "sorted.h"

using namespace std;

int main() {
    SortedArray sarray;
    string command;
    cin >> command;
    while(command != "quit") {
        if (command == "ascend") {
            vector<int> v = sarray.GetSortedAscending();
            for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        } else if (command == "descend") {
            vector<int> v = sarray.GetSortedDescending();
            for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        } else if (command == "max") {
            cout << sarray.GetMax() << endl;
        } else if (command == "min") {
            cout << sarray.GetMin() << endl;
        } else { 
            //input ints
            int input = stoi(command);
            sarray.AddNumber(input);
        }
        cin >> command;
    }
}