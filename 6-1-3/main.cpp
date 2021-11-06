#include <iostream>

#include "accounts.h"

using namespace std;

int main() {
    AccountManager am;
    am.acc_nums = 0;
    while(true) {
        cout << "Job?\n";
        char command;
        int id1, id2, bal;
        cin >> command;
        
        if (command == 'N') {
            if (am.acc_nums < 10) {
                am.newAcc(am.acc_nums);
                cout << "Account for user " << am.acc_nums << " registered\n";
                am.check(am.acc_nums);
                am.acc_nums += 1;
            } else {
                cout << "less than 10\n"; 
            }
        } else if (command == 'D') {
            cin >> id1 >> bal;
            if (id1 >= am.acc_nums) {
                cout << "Account does not exist\n";
            } else {
                am.deposit(id1, bal);
                am.check(id1);
            }

        } else if (command == 'W') {
            cin >> id1 >> bal;
            if (id1 >= am.acc_nums) {
                cout << "Account does not exist\n";
            } else {
                am.withdraw(id1, bal);
                am.check(id1);
            }
        } else if (command == 'T') {
            cin >> id1 >> id2 >> bal;
            if (id1 >= am.acc_nums || id2 >= am.acc_nums) {
                cout << "Account does not exist\n";
            } else {
                am.transfer(id1, id2, bal);
                am.check(id1);
                am.check(id2);
            }
        } else if (command == 'Q') {
            break;
        }
    }
}