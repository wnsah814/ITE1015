#include "shapes.h"
using namespace std;

int main() {
    int cwidth, cheight; //canvas width, height
    cin >> cwidth >> cheight;

    string shape;
    cin >> shape;
    while (shape != "quit") {
        if (shape == "rect") {
            int topLeftX, topLeftY, width, height;
            char brush;
            cin >> topLeftX >> topLeftY >> width >> height >> brush;
            Rectangle rec(topLeftX, topLeftY, width, height, brush);
            cout << "Area: " << rec.GetArea() << endl;
            cout << "Perimeter: " << rec.GetPerimeter() << endl;
            rec.Draw(cwidth, cheight);

        } else if (shape == "square") {
            int topLeftX, topLeftY, length;
            char brush;
            cin >> topLeftX >> topLeftY >> length >> brush;
            Square sq(topLeftX, topLeftY, length, brush);
            cout << "Area: " << sq.GetArea() << endl;
            cout << "Perimeter: " << sq.GetPerimeter() << endl; 
            sq.Draw(cwidth, cheight);
        } else if (shape == "diamond") {
            int topCenterX, topCenterY, distance;
            char brush;
            cin >> topCenterX >> topCenterY >> distance >> brush;
            Diamond dia(topCenterX, topCenterY, distance, brush);
            cout << "Area: " << dia.GetArea() << endl;
            cout << "Perimeter: " << dia.GetPerimeter() << endl;
            dia.Draw(cwidth, cheight);
        }
        cin >> shape;
    }

}