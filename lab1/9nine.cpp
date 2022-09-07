#include <iostream>
using namespace std;

void sort(int a[], int n, bool asc) {
	for(int i = 0; i < n - 1; i++) {
		int num = a[i], flag = 0, idx;
		for(int j = i + 1; j < n; j++)
			if(asc) {
				if(a[j] < num) {
					num = a[j];
					idx = j;
					flag = 1;
				}
			} else {
				if(a[j] > num) {
					num = a[j];
					idx = j;
					flag = 1;
				}
			}
			
		if(flag != 0) {
			int temp = a[i];
			a[i] = num;
			a[idx] = temp;
		}
	}
}

void print(int a[], int n) {
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	int a[] = {4, 3, 9, 6, 0, 1, 5, 8, 7, 2};
	int n = sizeof(a) / sizeof(a[0]);
	
	// ASC
	sort(a, n, true);
	print(a, n);
	
	// DESC
	sort(a, n, false);
	print(a, n);
	
	return 0;
}
