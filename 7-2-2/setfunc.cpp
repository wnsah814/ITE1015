#include <iostream>
#include <set>
#include "setfunc.h"

using namespace std;

set<int> parseSet(const string& str) { 
    set<int> s;

    size_t sp = 0, ep;
    string num;
    while (true) {
        ep = str.find(' ', sp);
        num = str.substr(sp, ep - sp);
        s.insert(stoi(num));
        if (ep == str.size() - 1) {
            break;
        }
        sp = ep + 1;
    }
    return s;
}

void printSet(const set<int>& s) {
    cout << "{ ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << "}\n";
}

set<int> getIntersection(const set<int>& set0, const set<int>& set1) {
    set<int> s;
    for (set<int>::iterator it = set0.begin(); it != set0.end(); it++) {
        if (set1.find(*it) != set1.end()) {
            s.insert(*it);
        }
    }
    return s;
}

set<int> getUnion(const set<int> set0, const set<int>& set1) {
    set<int> s;
    for (set<int>::iterator it = set0.begin(); it != set0.end(); it++) {
        s.insert(*it);
    }
    for (set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
        s.insert(*it);
    }
    return s;
}

set<int> getDifference(const set<int>& set0, const set<int>& set1) {
    set<int> s = set0;
    for (set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
        if (set0.find(*it) != set0.end()) {
            s.erase(*it);
        }
    }
    return s;
}