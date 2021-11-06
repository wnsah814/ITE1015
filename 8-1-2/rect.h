#ifndef __numbers__
#define __numbers__

#include <iostream>

class Rectangle {
public:
    Rectangle(int width, int height);
    int getArea();
    int getPerimeter();
protected:
    int width_;
    int height_;
};

class Square: public Rectangle {
public:
    Square (int width);
    void print();
};

class NonSquare: public Rectangle {
public:
    NonSquare (int width, int height);
    void print();
};

#endif