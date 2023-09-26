#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

    vector<string> dump;
    stringstream ss;

    while (command != "quit") {
        if (command == "add") {
            string shape;
            cin >> shape;
            char brush;
            if (shape == "rect") {
                int topLeftX, topLeftY, width, height;
                cin >> topLeftX >> topLeftY >> width >> height >> brush;
                object.push_back(new Rectangle(topLeftX, topLeftY, width, height, brush));
                ss << " rect " << topLeftX << " " << topLeftY << " "  << width << " " << height << " " << brush;
                dump.push_back(ss.str());
                ss.str("");
            } else if (shape == "diamond") {
                int topCenterX, topCenterY, distance;
                cin >> topCenterX >> topCenterY >> distance >> brush;
                object.push_back(new Diamond(topCenterX, topCenterY, distance, brush));
                ss << " diamond " << topCenterX << " " << topCenterY << " "  << distance << " " << brush;
                dump.push_back(ss.str());
                ss.str("");
            } else if (shape == "tri_up") {
                int topCenterX, topCenterY, height;
                cin >> topCenterX >> topCenterY >> height >> brush;
                object.push_back(new UpTriangle(topCenterX, topCenterY, height, brush));
                ss << " tri_up " << topCenterX << " " << topCenterY << " "  << height << " " << brush;
                dump.push_back(ss.str());
                ss.str("");
            } else if (shape == "tri_down") {
                int bottomCenterX, bottomCenterY, height;
                cin >> bottomCenterX >> bottomCenterY >> height >> brush;
                object.push_back(new DownTriangle(bottomCenterX, bottomCenterY, height, brush));
                ss << " tri_down " << bottomCenterX << " " << bottomCenterY << " "  << height << " " << brush;
                dump.push_back(ss.str());
                ss.str("");
            }
        } else if (command == "delete") {
            int index;
            cin >> index;
            if (index < object.size()) {
                object.erase(object.begin() + index);
                dump.erase(dump.begin() + index);
                canvas.Clear();
                for (int i = 0; i < object.size(); i++) {
                    object[i] -> Draw(&canvas);
                }
            }
        } else if (command == "draw") {
            for (int i = 0; i < object.size(); i++) {
                object[i] -> Draw(&canvas);
            }
            canvas.Print();
        } else if (command == "dump") {
            for (int i = 0; i < dump.size(); i++) {
                cout << i << dump[i] << endl;
            }
        } else if (command == "resize") {
            int newWidth, newHeight;
            cin >> newWidth >> newHeight; 
            canvas.Resize(newWidth, newHeight);
            canvas.Clear();
            for (int i = 0; i < object.size(); i++) {
                object[i] -> Draw(&canvas);
            }
        }
        cin >> command;
    }
    return 0;
}