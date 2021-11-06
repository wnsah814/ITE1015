#include "shapes.h"
#define pi 3.14
//int center_x, int center_y, 
Circle::Circle() {
    _center_x = 0;
    _center_y = 0;
    _radius = 0;
}

Circle::Circle(int x, int y, int r) {
    _center_x = x;
    _center_y = y;
    _radius = r;
}

double Circle::area() {
    return pi * _radius * _radius;
}

double Circle::perimeter() {
    return 2 * pi * _radius;
}

Retangle::Retangle() {
    _x1 = 0;
    _y1 = 0;
    _x2 = 0;
    _y2 = 0;
}

Retangle::Retangle(int x1, int y1, int x2, int y2) {
    _x1 = x1;
    _y1 = y1;
    _x2 = x2;
    _y2 = y2;
}

long long Retangle::area() {
    return (_x2 - _x1) * (_y1 - _y2);
}

long long Retangle::perimeter() {
    return 2 * ( (_x2 - _x1) + (_y1 - _y2) );
}

