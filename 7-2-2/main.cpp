#include <iostream>
#include <string>
#include <set>
#include "setfunc.h"

//#include "setfunc.h"
using namespace std;


int main() {
    string input;
    while (true) {
        getline(cin, input);
        if (input[0] == '0') break;

        size_t firstOpenIndex = input.find("{");
        size_t firstCloseIndex = input.find("}", firstOpenIndex);
        size_t secondOpenIndex = input.find("{", firstCloseIndex);
        size_t secondCloseIndex = input.find("}", secondOpenIndex);
        string first = input.substr(firstOpenIndex + 2, firstCloseIndex - firstOpenIndex-3);
        string second = input.substr(secondOpenIndex + 2, secondCloseIndex - secondOpenIndex - 3);
        set<int> s0 = parseSet(first);
        set<int> s1 = parseSet(second);
        set<int> resultSet;

        size_t operatorLocation = firstCloseIndex + 2;
        char op = input[operatorLocation];
        if (op == '+') {
            resultSet = getUnion(s0, s1);
        } else if (op == '*') {
            resultSet = getIntersection(s0, s1);
        } else if (op == '-') {
            resultSet = getDifference(s0, s1);
        }
        printSet(resultSet);
    }
    return 0;
}