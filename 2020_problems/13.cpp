#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Wheel {
  double diameter;
  double weight;
};

class Vehicle {
  protected:
    string _name;
    double _weight;
    Wheel* _wheels;

  public:
    Vehicle(const string& name, double weight) : _name(name), _weight(weight), _wheels(NULL) {}
    virtual ~Vehicle() { }
    string getName() { return _name; }
    virtual double getWeight() = 0;
};

class MotorCycle : public Vehicle {
  public:
    MotorCycle(const string& name, double weight) {
      _wheels = new Wheel[2];
      for (int i = 0; i < 2; ++i) {
        _wheels[i].diameter = 19.0;
        _wheels[i].weight = 2.0;
      }
    }
    ~MotorCycle() { };
    double getWeight() { return _weight + 2 * _wheels[0].weight; }
};

class Truck : public Vehicle {
  private:
    double _loadWeight;
  public:
    Truck(const string& name, double weight) {
      _wheels = new Wheel[6];
      for (int i = 0; i < 6; ++i) {
        _wheels[i].diameter = 24.0;
        _wheels[i].weight = 40.0;
      }
    }
    ~Truck() { }
    void addLoad(double weight) { _loadWeight += weight; }
    double getWeight() { return _weight + _loadWeight + 6 * _wheels[0].weight; }
};

int main() {
  vector<Vehicle*> vehicles;
  vehicles.push_back(new MotorCycle("bike1", 100));
  vehicles.push_back(new Truck("truck1", 10000));
  static_cast<Truck*>(vehicles[1]) -> addLoad(1000);

  for (int i = 0; i < vehicles.size(); ++i) {
    cout << vehicles[i] -> getName() << " " << vehicles[i] -> getWeight() << endl;
    delete vehicles[i];
  }

  return 0;
}