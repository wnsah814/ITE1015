#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    double score;
};

int main(int argc, char** argv) {
    int N = (argc-1)/2;
    Person* arr = new Person[N];

    for (int i = 0; i < N; i++) {
        arr[i].name = argv[2*i+1];
        arr[i].score = atof(argv[2*i+2]);
    }

    for (int i = 0; i < N; i++) {
        cout << "Name:" << arr[i].name << ", ";
        cout << "Score:" << arr[i].score << endl;
    }
    delete[] arr;
    return 0;
}