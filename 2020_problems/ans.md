### 1번

1. T
2. F
3. F
4. T
5. F
6. T
7. F
8. F
9. T
10. F
11. F
12. T
13. F
14. F
15. F

### 2번

1. A
2. D
3. D
4. E

### 3번

Base

### 4번

```c++
#include <iostream>

class Vector {
  public:
    int * x;
    int size;

    Vector() : x(NULL), size(0) {}
    Vector(int n) {
      size = n;
      x = new int [size];
    }

    ~Vector() {
      delete[] x;
    }

    void Resize(int n) {
      delete[] x;
      x = new int[size = n];
    }
};

int main() {
  Vector *p = new Vector(10);
  for (int j = 0; j < p -> size; ++j) {
    p -> x[j] = j;
  }

  Vector *q = new Vector[10];
  for (int i = 0; i < 10; ++i) {
    q[i].Resize(i);
  }
}
```

### 5번

(a), (c)

### 6번

1. A
2. B

### 7번

A, D

### 8번

3

### 9번

1. compile error, i와 j는 부모클래스의 private 변수이다.
2. Inside Q
3. 0 5
4.

- Parent Child
- ~Child ~Parent
- Parent Child Test
- ~Test ~Child ~Parent

### 10번

```c++
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int* num = new int;
  int* numArr = new int[n];

  *num = n;
  for (int i = 0; i < n; ++i) {
    numArr[i] = i;
  }

  cout << *num << endl;
  for (int i = 0; i < n; ++i) {
    cout << numArr[i] << " ";
  }
  cout << endl;

  delete num;
  delete[] numArr;

  return 0;
}
```

### 11번

40

50

50

40

### 12번

65 66

### 13번

```c++
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
    MotorCycle(const string& name, double weight) : Vehicle(name, weight) {
      _wheels = new Wheel[2];
      for (int i = 0; i < 2; ++i) {
        _wheels[i].diameter = 19.0;
        _wheels[i].weight = 2.0;
      }
    }
    ~MotorCycle() {
      delete[] _wheels;
    };
    double getWeight() { return _weight + 2 * _wheels[0].weight; }
};

class Truck : public Vehicle {
  private:
    double _loadWeight;
  public:
    Truck(const string& name, double weight) : Vehicle(name, weight) {
      _wheels = new Wheel[6];
      for (int i = 0; i < 6; ++i) {
        _wheels[i].diameter = 24.0;
        _wheels[i].weight = 40.0;
      }
    }
    ~Truck() {
      delete[] _wheels;
    }
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
```

### 14번

a (2, 3)

(2, 3)

b (1, 2)

(2, 3)

### 15번

C

### 16번

error

### 17번

```c++
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Movie {
  public:
    enum { CHILDRENS, REGULAR, NEW_RELEASE, NONE };
    Movie() : _priceCode(NONE) {}
    virtual ~Movie() {}
    Movie(string name, int priceCode) {
      _name = name;
      _priceCode = priceCode;
    }
    int priceCode() const {
      return _priceCode;
    }

    static void add(string name, int priceCode) {
      _movies[name] = Movie(name, priceCode);
    }

    static const Movie & get(string name) {
      return _movies[name];
    }
  public:
    string _name;
    int _priceCode;
    static map<string, Movie> _movies;
};

map<string, Movie> Movie::_movies;

int main() {
  Movie::add("Batman begins", Movie::REGULAR);
  Movie::add("Moana", Movie::CHILDRENS);
  Movie::add("Wonder woman 1984", Movie::NEW_RELEASE);

  cout << "priceCode" << Movie::get("Moana").priceCode() << endl;

  return 0;
}
```
