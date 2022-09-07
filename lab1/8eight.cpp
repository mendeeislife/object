#include <iostream>
using namespace std;

double arrAvg(int a[], int n) {
	int sum = 0;
	double avg;
	for(int i = 0; i < n; i++)
		sum += a[i];
	avg = sum / n;
	return avg;
}

int main() {
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(a) / sizeof(a[0]);
			
	cout << "AVG: " << arrAvg(a, n) << endl;
	
	
	return 0;
}
