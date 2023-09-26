#ifndef __MY_VECTOR_H__
#define __MY_VECTOR_H__

#include <iostream>

class MyVector2
{
public:
    MyVector2();
    MyVector2(int length);
    MyVector2(const MyVector2& mv);
    ~MyVector2();
    MyVector2& operator=(const MyVector2& b) { return *this; };
    MyVector2 operator+(const MyVector2& b);
    MyVector2 operator-(const MyVector2& b);
    MyVector2 operator+(const int b);
    MyVector2 operator-(const int b);
    friend std::ostream& operator<< (std::ostream& out, MyVector2& b);
    friend std::istream& operator>> (std::istream& in, MyVector2& b);
private:
    int length;
    double *a;
};
#endif