#include "message.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

MessageBook::MessageBook() {

}

MessageBook::~MessageBook() {

}

void MessageBook::AddMessage(int number, const std::string& message) {
    //messages_.insert({number, message});
    messages_[number] = message;
}   

void MessageBook::DeleteMessage(int number) {
    messages_.erase(number);
}

std::vector<int> MessageBook::GetNumbers() {
    std::vector<int> v;
    for (std::map<int, std::string>::iterator it = messages_.begin(); it != messages_.end(); it++) {
        v.push_back(it -> first);
    }
    sort(v.begin(), v.end());
    return v;
}

const std::string& MessageBook::GetMessage(int number) {
    if (messages_.find(number) != messages_.end()) {
        return messages_[number];
    } else {
        static const std::string empty = " ";
        return empty;
    }
}