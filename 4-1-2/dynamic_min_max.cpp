#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i=0; i<N; i++) {
		cin >> arr[i];
	}
	int max = arr[0], min = arr[0];
	for (int i=0; i<N; i++) {
		if (max < arr[i]) {
			max = arr[i];
		} else if(min > arr[i]) {
			min = arr[i];
		}
	}
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
	delete[] arr;	
	return 0;
}