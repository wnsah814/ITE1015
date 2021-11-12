#include <iostream>
#include <vector>
#include <string>
#include "animal.h"

using namespace std;

int main() {
    char command;
    string name;
    int age;
    cin >> command;
    vector<Animal*> animals;

    while (command != '0') {
        if (command == 'z') {
            int numStripe;
            cin >> name >> age >> numStripe;
            animals.push_back(new Zebra(name, age, numStripe));
        } else if (command == 'c') {
            string favoriteToy;
            cin >> name >> age >> favoriteToy; 
            animals.push_back(new Cat(name, age, favoriteToy));
        }

        cin >> command;
    }
    //printInfo
    for (int i = 0; i < animals.size(); i++) {
        animals[i] -> printInfo();
    }

    //Free
    for (int i = 0; i < animals.size(); i++) {
        delete animals[i];
    }

    return 0;
}