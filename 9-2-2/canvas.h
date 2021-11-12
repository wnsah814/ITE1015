#ifndef __canvas__
#define __canvas__

using namespace std;

class Canvas {
public:
    Canvas(size_t _row, size_t _col);
    ~Canvas();
    void Resize(size_t w, size_t h);
    //bool DrawPixel(int x, int y, char brush);
    void DrawPixel(int x, int y, char brush);
    void Print();
    void Clear();
private:
    int row, col;
    vector< vector<char> > arr;
};

class Shape {
public:
    Shape(int _startX, int _startY, char _brush);
    virtual ~Shape();
    virtual void Draw(Canvas* canvas) {};
protected:
    int startX, startY;
    //int canvasWidth, canvasHeight;
    char brush;
};

class Rectangle : public Shape { 
public:
    Rectangle(int _topLeftX, int _topLeftY, int _width, int _height, char brush);
    void Draw(Canvas* canvas);
private:
    int width, height;
};

class UpTriangle : public Shape {
public:
    UpTriangle(int _topCenterX, int _topCenterY, int _height, char brush);
    void Draw(Canvas* canvas);
private:
    int height;
};

class DownTriangle : public Shape {
public:
    DownTriangle(int _bottomCenterX, int _BottomCenterY, int _height, char brush);
    void Draw(Canvas* canvas);
private:
    int height;
};

class Diamond : public Shape {
public:
    Diamond(int _topCenterX, int _topCenterY, int _distance, char brush);
    void Draw(Canvas* canvas);
private:
    int distance;
};

#endif