#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "message.h"
using namespace std;

int main() {
    string command;
    int phoneNumber;
    string message;
    MessageBook mb;

    cin >> command;
    while (command != "quit") {
        if (command == "add") {
            cin.ignore();
            string s;
            getline(cin, s);
            int found = s.find(" ");
            if (found != string::npos) {
                phoneNumber = stoi(s.substr(0, found));
                message = s.substr(found+1);
                mb.AddMessage(phoneNumber, message);
            } else {
                phoneNumber = stoi(s);
                mb.AddMessage(phoneNumber, " ");
            }
            
        } else if (command == "delete") {
            cin >> phoneNumber;
            mb.DeleteMessage(phoneNumber);
        } else if (command == "print") {
            cin >> phoneNumber;
            cout << mb.GetMessage(phoneNumber) << endl << endl;
        } else if (command == "list") {
            vector<int> v = mb.GetNumbers();
            for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
                cout << *it << ": " << mb.GetMessage(*it) << endl;
            }
        }
        cin >> command;
    }
    return 0;
}