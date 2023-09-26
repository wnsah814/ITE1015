#include <iostream>
#include <vector>
#include <algorithm>
#include "intset.h"
using namespace std;

IntegerSet::IntegerSet() {

}

IntegerSet::~IntegerSet() {

}

void IntegerSet::AddNumber(int num) {
    if (find(numbers_.begin(), numbers_.end(), num) == numbers_.end()) {
        numbers_.push_back(num);
    }
    sort(numbers_.begin(), numbers_.end());

    for (vector<int>::iterator it = numbers_.begin(); it != numbers_.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void IntegerSet::DeleteNumber(int num) {
    vector<int>::iterator found = find(numbers_.begin(), numbers_.end(), num);
    if (found != numbers_.end()) {
        numbers_.erase(found);
    }
    for (vector<int>::iterator it = numbers_.begin(); it != numbers_.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int IntegerSet::GetItem(int pos) {
    if (numbers_.size() > pos) {
        return numbers_[pos];
    } else {
        return -1;
    }
        
}

vector<int> IntegerSet::GetAll() {
    return numbers_;
}