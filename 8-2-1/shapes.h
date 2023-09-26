#ifndef __shapes__
#define __shapes__

#include <cmath>
#include <iostream>
#include <string>

class Shape {
public:
    Shape();
    Shape(int topFirstX, int topFirstY, char brush);
    double GetArea(int width, int height) {};
    int GetPerimeter() {};
    void Draw(int canvas_width, int canvas_height) {};

protected:
    int _topFirstX, _topFirstY;
    char _brush;
};

class Rectangle: public Shape {
public:
    Rectangle(int topLeftX, int topLeftY, int width, int height, char brush);
    double GetArea();
    int GetPerimeter();
    void Draw(int canvas_width, int canvas_height);
private:
    int _width, _height;
};

class Square: public Shape {
public:
    Square(int topLeftX, int topLeftY, int length, char brush);
    double GetArea();
    int GetPerimeter();
    void Draw(int canvas_width, int canvas_height);
private:
    int _length;
};

class Diamond: public Shape {
public:
    Diamond(int topCenterX, int topCenterY, int distance, char brush);
    double GetArea();
    int GetPerimeter();
    void Draw(int canvas_width, int canvas_height);
private:
    int _distance;
};

#endif