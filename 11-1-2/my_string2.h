#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>

class MyString2 {
public:
    MyString2() {};
    MyString2(std::string s);
    MyString2(const MyString2& mystr);
    MyString2& operator=(const MyString2& b) { return *this; };
    MyString2 operator+(const MyString2& b);
    MyString2 operator*(const int b);
    friend std::ostream& operator<<(std::ostream& out, MyString2& my_string);
    friend std::istream& operator>>(std::istream& in, MyString2& my_string);
private:
    std::string str;
};

#endif