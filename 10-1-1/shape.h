#ifndef __shape__
#define __shape__

class Shape {
public:
  Shape(double _width, double _height);
  virtual double getArea() = 0;
protected:
  double width, height;
};

class Triangle: public Shape {
public:
  Triangle(double _width, double _height);
  double getArea();
};


class Rectangle: public Shape {
public:
  Rectangle(double _width, double _height);
  double getArea();
};


#endif