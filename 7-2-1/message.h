#ifndef __message__
#define __message__

#include <iostream>
#include <string>
#include <vector>
#include <map>

class MessageBook {
public: 
    MessageBook();
    ~MessageBook();
    void AddMessage(int number, const std::string& message);
    void DeleteMessage(int number);
    std::vector<int> GetNumbers();
    const std::string& GetMessage(int number);

private:
    std::map<int, std::string> messages_;
};

#endif