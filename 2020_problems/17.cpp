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