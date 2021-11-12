#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

Animal::Animal(string name, int age) {
    _name = name;
    _age = age;
}

void Animal::printInfo() {
    //nothing
}

Zebra::Zebra(string name, int age, int numStripe): Animal(name, age) {
    _numStripe = numStripe;
}

void Zebra::printInfo() {
    cout << "Zebra, Name: " << _name << ", Age: " << _age << ", Number of stripes: " << _numStripe << endl;
}

Cat::Cat(string name, int age, string favoriteToy): Animal(name, age) {
    _favoriteToy = favoriteToy;
}   

void Cat::printInfo() {
    cout << "Zebra, Name: " << _name << ", Age: " << _age << ", Favorite Toy: " << _favoriteToy << endl;
}
