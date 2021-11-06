#include <iostream>
#include <string>

using namespace std;

struct Person {
	string name;
	int age;
};

int main() {
	int N;
	cin >> N;
	Person* arr = new Person[N];
	for (int i=0; i<N; i++) {
		cin >> arr[i].name >> arr[i].age;
	}
	for (int i=0; i<N; i++) {
		cout << "Name:" << arr[i].name << ", Age:" << arr[i].age << endl;
	}
	delete[] arr;
	return 0;
}
