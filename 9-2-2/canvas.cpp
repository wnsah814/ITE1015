#include <iostream>
#include <vector>
#include <array>
#include "canvas.h"

using namespace std;

Canvas::Canvas(size_t _row, size_t _col) {
    row = _row;
    col = _col;
    for (int i = 0; i < col; i++) {
        vector<char> element(row, '.');
        arr.push_back(element);
    }
}

Canvas::~Canvas() {

}

void Canvas::Resize(size_t w, size_t h) {
    row = w;
    col = h;

    arr.resize(h);
    for (int i = 0; i < arr.size(); i++) {
        arr[i].resize(w);
    }
}

bool Canvas::DrawPixel(int x, int y, char brush) {
    if (x >= row || y >= col) {
        return false;
    } else {
        arr[y][x] = brush;
        return true;
   }
}

void Canvas::Print() {
    cout << " ";
    for (int i = 0; i < row; i++) {
        cout << i % 10;
    }
    cout << endl;

    for (int i = 0; i < col; i++) {
        cout << i % 10;
        for (int j = 0; j < row; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            arr[i][j] = '.';
        }
    }
}

Shape::Shape(int _startX, int _startY, char _brush) {
    startX = _startX;
    startY = _startY;
    brush = _brush;
}

Shape::~Shape() {

}

Rectangle::Rectangle(int _topLeftX, int _topLeftY, int _width, int _height, char _brush):
    Shape(_topLeftX, _topLeftY, _brush) {
    width = _width;
    height = _height;
}

void Rectangle::Draw(Canvas* canvas) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas -> DrawPixel(startX + j, startY + i, brush);
        }
    }
}

UpTriangle::UpTriangle(int _topCenterX, int _topCenterY, int _height, char _brush):
    Shape(_topCenterX, _topCenterY, _brush) {
    height = _height;
}

void UpTriangle::Draw(Canvas* canvas) {
    int counter = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            canvas -> DrawPixel(startX - j, startY + i, brush);
            canvas -> DrawPixel(startX + j, startY + i, brush);
        }
    }
}

DownTriangle::DownTriangle(int _bottomCenterX, int _BottomCenterY, int _height, char _brush):
    Shape(_bottomCenterX, _BottomCenterY, _brush) {
    height = _height;
}

void DownTriangle::Draw(Canvas* canvas) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            canvas -> DrawPixel(startX - j, startY - i, brush);
            canvas -> DrawPixel(startX + j, startY - i, brush);
        }
    }    
}

Diamond::Diamond(int _topCenterX, int _topCenterY, int _distance, char _brush):
    Shape(_topCenterX, _topCenterY, _brush) {
    distance = _distance;
}   

void Diamond::Draw(Canvas* canvas) {
    for (int i = 0; i <= distance; i++) {
        for (int j = 0; j <= i; j++) {
            canvas -> DrawPixel(startX - j, startY + i, brush);
            canvas -> DrawPixel(startX + j, startY + i, brush);
        }
    }
    for (int i = 1; i <= distance; i++) {
        for (int j = distance - i; j >= 0; j--) {
            canvas -> DrawPixel(startX - j, startY + i + distance, brush);
            canvas -> DrawPixel(startX + j, startY + i + distance, brush);
        }
    }
}