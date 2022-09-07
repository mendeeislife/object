#include <iostream>
using namespace std;

int main() {
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(a) / sizeof(a[0]);
	int count = 0;
	
	for(int i = 0; i < n; i++)
		if(a[i] % 2 == 0)
			count++;
			
	cout << "Number of even: " << count << endl;
	
	
	return 0;
}
