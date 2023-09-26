#include "shapes.h"
using namespace std;

Shape::Shape() {
    
}

Shape::Shape(int topFirstX, int topFirstY, char brush) {
    _topFirstX = topFirstX;
    _topFirstY = topFirstY;
    _brush = brush;
}

//Shape 메소드 필요한가?

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
    for (int i = 0; i < canvas_width; i++) {
        cout << i;
    } cout << endl;

    for (int i = 0; i < canvas_height; i++) {
        cout << i;
        for (int j = 0; j < canvas_width; j++) {
            if (i >= _topFirstY && j >= _topFirstX && j < _topFirstX + _width && i < _topFirstY + _height) {
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
    for (int i = 0; i < canvas_width; i++) {
        cout << i;
    } cout << endl;

    for (int i = 0; i < canvas_height; i++) {
        cout << i;
        for (int j = 0; j < canvas_width; j++) {
            if (i >= _topFirstY && j >= _topFirstX && j < _topFirstX + _length && i < _topFirstY + _length) {
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
    return _distance*2 * _distance*2 / 2;
}   

int Diamond::GetPerimeter() {
    return sqrt(_distance*_distance*2)*4;
}

void Diamond::Draw(int canvas_width, int canvas_height) {
    cout << " ";
    for (int i = 0; i < canvas_width; i++) {
        cout << i;
    } cout << endl;
    int counter = 0;
    int check = 0;
    int startDecrease = 0;
    for (int i = 0; i < canvas_height; i++) {
        cout << i;
        for (int j = 0; j < canvas_width; j++) {
            if (i >= _topFirstY && i <= _topFirstY + 2 * _distance && j >= _topFirstX - counter && j <= _topFirstX + counter) {
                cout << _brush;
                check = 1;
            }
            else {
                cout << ".";
            }   
        }
        if (check == 1) {
            if (startDecrease == 0) {
                if (counter < _distance) {
                    counter++;
                } else {
                    startDecrease = 1;
                }
            }
            if (startDecrease == 1) {
                counter--;
            }
            check == 0;
        }
        cout << endl;
    }
}