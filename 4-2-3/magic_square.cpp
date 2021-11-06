#include <iostream>
using namespace std;

void magic_square(int* arr[], int N) {
	for (int i = 0 ; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = 0;
		}
	}
	int m = 0, n = N/2;
	arr[m][n] = 1;
	m -= 1;
	n += 1;
	int num = 2;
	while(num != N*N+1) {
		if (m>=0) {
			if(n < N) {
				if(arr[m][n] == 0) {
					arr[m][n] = num++;
					if(m==0&&n==N-1) {
						m += 1;
					} else {
						m -= 1;
						n += 1;
					}
				} else {
					m += 2;
					n -= 1;
				}
			} else {
				n = 0;
				while(arr[m][n]>0) {
					n++;
				}
			}
		} else {
			m = N-1;
			while(arr[m][n]>0) {
				m--;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	if (N < 3 || N % 2 == 0) { return 0; }

	int** arr = new int*[N];
	for(int i = 0; i < N; ++i)
		arr[i] = new int[N];
	
	
	magic_square(arr, N);

	// print magic square
	for (int i = 0 ; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i =0; i<N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	
	return 0;
}
