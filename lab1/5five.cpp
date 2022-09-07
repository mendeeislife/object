#include <iostream>
using namespace std;

int main() {
	int n, x, sum = 0, mul = 1;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
		mul *= x;
	}
	
	cout << "Sum: " << sum << endl;
	cout << "Multiply: " << mul << endl;
	
	return 0;
}
