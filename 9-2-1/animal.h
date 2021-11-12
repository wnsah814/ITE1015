#ifndef __animal__
#define __animal__ 

class Animal {
public:
    Animal(std::string name, int age);
    virtual ~Animal() {};
    virtual void printInfo();
protected:
    std::string _name;
    int _age;
};

class Zebra: public Animal {
public:
    Zebra(std::string name, int age, int numStripe);
    ~Zebra() {};
    void printInfo();
private:
    int _numStripe;
};

class Cat: public Animal {
public:
    Cat(std::string name, int age, std::string favoriteToy);
    ~Cat() {};
    void printInfo();
private:
    std::string _favoriteToy;
};


#endif