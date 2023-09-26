#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b;
	c = a + b;
	cout << c << endl;
	cout << c[0] << endl;
	int len = c.size();
	cout << c[len-1] << endl;
	
	return 0;
}
