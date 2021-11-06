#ifndef __accounts__
#define __accounts__

class Account {
    int _id, _balance;
public:
    Account();
    Account(int id, int bal);
    void addBal(int val);
    const int getBal() const;
};

class AccountManager {
    Account* arr = new Account[10];
public:
    int acc_nums;
    AccountManager();
    ~AccountManager();
    void newAcc(int id);
    void deposit(int id, int val);
    void withdraw(int id, int val);
    void transfer(int id1, int id2, int val);
    void check(int id) const;
};
#endif