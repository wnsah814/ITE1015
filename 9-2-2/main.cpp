#include <iostream>
#include <vector>
#include "canvas.h"
using namespace std;

int main() {
    int width, height;
    cin >> width >> height;
    Canvas canvas(width, height);
    canvas.Print();
    vector<Shape*> object;
    string command;
    cin >> command;

    while (command != "quit") {
        if (command == "add") {
            string shape;
            cin >> shape;
            char brush;
            if (shape == "rect") {
                int topLeftX, topLeftY, width, height;
                cin >> topLeftX >> topLeftY >> width >> height >> brush;
                object.push_back(new Rectangle(topLeftX, topLeftY, width, height, brush));
            } else if (shape == "diamond") {
                int topCenterX, topCenterY, distance;
                cin >> topCenterX >> topCenterY >> distance >> brush;
                object.push_back(new Diamond(topCenterX, topCenterY, distance, brush));
            } else if (shape == "tri_up") {
                int topCenterX, topCenterY, height;
                cin >> topCenterX >> topCenterY >> height >> brush;
                object.push_back(new UpTriangle(topCenterX, topCenterY, height, brush));
            } else if (shape == "tri_down") {
                int bottomCenterX, bottomCenterY, height;
                cin >> bottomCenterX >> bottomCenterY >> height >> brush;
                object.push_back(new DownTriangle(bottomCenterX, bottomCenterY, height, brush));
            }
        } else if (command == "delete") {
            int index;
            cin >> index;
            //object.erase(index);
        } else if (command == "draw") {
            for (int i = 0; i < object.size(); i++) {
                object[i] -> Draw(&canvas);
            }
            canvas.Print();
        } else if (command == "dump") {
            for (int i = 0; i < object.size(); i++) {
                cout << i << "" << endl;
            }
        } else if (command == "resize") {
            int newWidth, newHeight;
            cin >> newWidth >> newHeight; 
            canvas.Resize(newWidth, newHeight);
        }
        cin >> command;
    }
    return 0;
}