#include "rect.h"
using namespace std;
Rectangle::Rectangle(int width, int height) {
    width_ = width;
    height_ = height;
}

int Rectangle::getArea() {
    return width_ * height_;
}

int Rectangle::getPerimeter() {
    return 2 * (width_ + height_);
}

Square::Square(int width) :
    Rectangle(width, width) {
}

void Square::print() {
    cout << width_ << "x" << height_ << " Square" << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Perimeter: " << getPerimeter() << endl;
}

NonSquare::NonSquare(int width, int height) :
    Rectangle(width, height) {

}

void NonSquare::print() {
    cout << width_ << "x" << height_ << " NonSquare" << endl;
    cout << "Area: " << getArea() << endl;
    cout << "Perimeter: " << getPerimeter() << endl;
}
