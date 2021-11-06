#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include "setfunc.h"

std::set<int> parseSet(const std::string& str) { 
    std::vector<int> v;
    std::set<int> s;
    std::stringstream stream;
    stream.str(str);
    int num;
    while (stream >> num) {
        v.push_back(num);
    }
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        s.insert(*it);
    }

    return s;
}

void printSet(const std::set<int>& s) {
    std::cout << "{ ";
    for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "}\n";
}

std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1) {
    std::set<int> s;
    for (std::set<int>::iterator it = set0.begin(); it != set0.end(); it++) {
        if (set1.find(*it) != set1.end()) {
            s.insert(*it);
        }
    }
    return s;
}

std::set<int> getUnion(const std::set<int> set0, const std::set<int>& set1) {
    std::set<int> s;
    for (std::set<int>::iterator it = set0.begin(); it != set0.end(); it++) {
        s.insert(*it);
    }
    for (std::set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
        s.insert(*it);
    }
    return s;
}

std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1) {
    std::set<int> s = set0;
    for (std::set<int>::iterator it = set1.begin(); it != set1.end(); it++) {
        if (set0.find(*it) != set0.end()) {
            s.erase(*it);
        }
    }
    return s;
}