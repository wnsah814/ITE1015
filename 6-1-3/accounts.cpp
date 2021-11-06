#include <iostream>

#include "accounts.h"
using namespace std;

Account::Account() {
    _id = 0;
    _balance = 0;
}

Account::Account(int id, int bal) {
    _id = id;
    _balance = bal;
}

void Account::addBal(int val) {
    _balance += val;
}

const int Account::getBal() const {
    return _balance;
}

AccountManager::AccountManager() {

}

AccountManager::~AccountManager() {
    delete[] arr;
}

void AccountManager::newAcc(int id) {
    arr[id] = Account(id, 0);
}
void AccountManager::deposit(int id, int val) {
    int ori_val = arr[id].Account::getBal();
    if (ori_val + val <= 1000000) {
        arr[id].Account::addBal(val);
        cout << "Success: Deposit to user " << id << " " << val << endl;
    } else {
        cout << "Failure: Deposit to user " << id << " " << val << endl;
    }
}

void AccountManager::withdraw(int id, int val) {
    int ori_val = arr[id].Account::getBal();
    if (ori_val - val >= 0) {
        arr[id].Account::addBal(-1*val);
        cout << "Success: Withdraw from user " << id << " " << val << endl;
    } else {
        cout << "Failure: Withdraw from user " << id << " " << val << endl;
    }
    
}

void AccountManager::transfer(int id1, int id2, int val) {
    int ori_val1 = arr[id1].Account::getBal();
    int ori_val2 = arr[id2].Account::getBal();
    if (ori_val1 - val >= 0 && ori_val2 + val <= 1000000) {
        arr[id1].Account::addBal(-1*val);
        arr[id2].Account::addBal(val);
        cout << "Success: Transfer from user " << id1 << " to user " << id2 << " " << val << endl;
    } else {
        cout << "Failure: Transfer from user " << id1 << " to user " << id2 << " " << val << endl;
    }

}

void AccountManager::check(int id) const {
    cout << "Balance of user " << id << ": " << arr[id].Account::getBal() << endl;
}