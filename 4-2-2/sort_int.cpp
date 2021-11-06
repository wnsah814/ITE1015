#include <iostream>

using namespace std;

void bs(int* arr, int len) {
	for (int i=0; i<len; i++) {
		for (int j=0; j<len-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	if (N <= 0) { return 0; }
	int* arr = new int[N];
	for (int i=0; i<N; i++) {
		cin >> arr[i];
	}
	bs(arr, N);
	
	for (int i=0; i<N; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;
	cout << endl;
	return 0;
}
