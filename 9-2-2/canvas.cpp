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

    //resize vector?
}

// bool Canvas::DrawPixel(int x, int y, char brush) {
//     if (arr[x][y] = brush) {
//         return true;
//     } else {
//         return false;
//     }
// }

void Canvas::DrawPixel(int x, int y, char brush) {
    arr[x][y] = brush;
}

void Canvas::Print() {
    cout << " ";
    for (int i = 0; i < row; i++) {
        cout << i;
    }
    cout << endl;

    for (int i = 0; i < col; i++) {
        cout << i;
        for (int j = 0; j < row; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    for (int i = 0; i < col; i++) {
        arr[i].clear();
    }
    arr.clear();

    for (int i = 0; i < col; i++) {
        vector<char> element(row, '.');
        arr.push_back(element);
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
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i >= startY && j >= startX && j < startX + width && i < startY + height) {
                canvas -> DrawPixel(i, j, brush);
            }
        }
    }
}

UpTriangle::UpTriangle(int _topCenterX, int _topCenterY, int _height, char _brush):
    Shape(_topCenterX, _topCenterY, _brush) {
    height = _height;
}

void UpTriangle::Draw(Canvas* canvas) {
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i >= startY && i <= startY + height && j >= startX - counter && j <= startX + counter) {
                canvas -> DrawPixel(i, j, brush);
                counter++;
            }
        }
    }
}

DownTriangle::DownTriangle(int _bottomCenterX, int _BottomCenterY, int _height, char _brush):
    Shape(_bottomCenterX, _BottomCenterY, _brush) {
    height = _height;
}

void DownTriangle::Draw(Canvas* canvas) {
    
}

Diamond::Diamond(int _topCenterX, int _topCenterY, int _distance, char _brush):
    Shape(_topCenterX, _topCenterY, _brush) {
    distance = _distance;
}   

void Diamond::Draw(Canvas* canvas) {
    int counter = 0;
    int check = 0;
    int startDecrease = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i >= startY && i <= startY + 2 * distance && j >= startX - counter && j <= startX + counter) {
                canvas -> DrawPixel(i, j, brush);
                check = 1;
            }
        }
        if (check == 1) {
            if (startDecrease == 0) {
                if (counter < distance) {
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
    }
}