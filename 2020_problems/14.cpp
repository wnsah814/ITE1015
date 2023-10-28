#include <iostream>
using namespace std;

class Point {
  private:
    double x, y;
  public:
    Point(double x_, double y_) : x(x_), y(y_) {}
    Point& operator++() { x++; y++; cout << "a "; return *this; }
    Point operator++(int) { Point temp(*this); x++; y++; cout << "b "; return temp; }
    friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

int main(int argc, char* argv[]) {
  Point p1(1, 2);
  cout << ++p1 << endl;
  cout << p1 << endl;

  Point p2(1, 2);
  cout << p2++ << endl;
  cout << p2 << endl;
  return 0;
}