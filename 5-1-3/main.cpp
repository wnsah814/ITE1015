#include <iostream>
#include "minmax.h"
using namespace std;

int main(int argc, char** argv) {
    int len = argc-1;
    int min, max;
    int* arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    getMinMax(arr, len, min, max);
    cout << "min: " << min << "\nmax: " << max << endl;
    return 0;
}