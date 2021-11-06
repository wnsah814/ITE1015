#ifndef __shapes__
#define __shapes__

class Circle {
	int _center_x, _center_y, _radius;
public:
	Circle();
	Circle(int x, int y, int r);
	double area();
	double perimeter();
};

class Retangle {
	int _x1, _y1, _x2, _y2;
public:
	Retangle();
	Retangle(int x1, int y1, int x2, int y2);
	long long area();
	long long perimeter();
};
 
#endif