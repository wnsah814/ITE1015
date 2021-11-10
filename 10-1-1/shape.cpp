#include "shape.h"

Shape::Shape(double _width, double _height) {
  width = _width;
  height = _height;
}

Triangle::Triangle(double _width, double _height): Shape(_width, _height) {

}

double Triangle::getArea() {
  return 0.5 * width * height;
}

Rectangle::Rectangle(double _width, double _height): Shape(_width, _height) {

}

double Rectangle::getArea() {
  return width * height;
}