#include "shapes.h"
#define ABS(x) (((x)<0)?(-(x)):(x))

using namespace std;

Shape::Shape() {
    
}

Shape::Shape(int topFirstX, int topFirstY, char brush) {
    _topFirstX = topFirstX;
    _topFirstY = topFirstY;
    _brush = brush;
}

Rectangle::Rectangle(int topLeftX, int topLeftY, int width, int height, char brush):
    Shape(topLeftX, topLeftY, brush) {
        _width = width;
        _height = height;
}

double Rectangle::GetArea() {
    return _width * _height;
}

int Rectangle::GetPerimeter() {
    return 2*(_width+_height);
}

void Rectangle::Draw(int canvas_width, int canvas_height) {
    cout << " ";
    for (int x = 0; x < canvas_width; x++) {
        cout << x;
    } cout << endl;

    for (int y = 0; y < canvas_height; y++) {
        cout << y;
        for (int x = 0; x < canvas_width; x++) {
            if (y >= _topFirstY && x >= _topFirstX && x < _topFirstX + _width && y < _topFirstY + _height) {
                cout << _brush;
            }
            else {
                cout << ".";
            }   
        }
        cout << endl;
    }
}

Square::Square(int topLeftX, int topLeftY, int length, char brush):
    Shape(topLeftX, topLeftY, brush) {
        _length = length;
}

double Square::GetArea() {
    return _length * _length;
}

int Square::GetPerimeter() {
    return 4 * _length;
}

void Square::Draw(int canvas_width, int canvas_height) {
    cout << " ";
    for (int x = 0; x < canvas_width; x++) {
        cout << x;
    } cout << endl;

    for (int y = 0; y < canvas_height; y++) {
        cout << y;
        for (int x = 0; x < canvas_width; x++) {
            if (y >= _topFirstY && x >= _topFirstX && x < _topFirstX + _length && y < _topFirstY + _length) {
                cout << _brush;
            }
            else {
                cout << ".";
            }   
        }
        cout << endl;
    }
}


Diamond::Diamond(int topCenterX, int topCenterY, int distance, char brush):
    Shape(topCenterX, topCenterY, brush) {
        _distance = distance;
}

double Diamond::GetArea() {
    return _distance * 2 * _distance * 2 / 2;
}   

int Diamond::GetPerimeter() {
    return sqrt(_distance*_distance*2)*4;
}

void Diamond::Draw(int canvas_width, int canvas_height) {
    cout << " ";
    for (int i = 0; i < canvas_width; i++) {
        cout << i;
    } cout << endl;

    int mx = _topFirstX, my = _topFirstY + _distance;
    int dx, dy;
    for (int y = 0; y < canvas_height; ++y) {
        cout << y;
        for (int x = 0; x < canvas_width; ++x) {
            dx = ABS(mx-x);
            dy = ABS(my-y);
            if (dx + dy <= _distance) {
                cout << _brush;
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
}