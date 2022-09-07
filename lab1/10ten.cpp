#include <iostream>
using namespace std;

int main() {
	int n;
	bool prime = true;
	cin >> n;
	
	if (n == 0 || n == 1)
    	prime = false;
	
	for(int i = 2; i <= n/2; i++) {
		if(n % i == 0) {
			prime = false;
			break; 
		}
	}
	
	if(prime)
		cout << "Anhnii too mun" << endl;
	else
		cout << "Anhnii too bish" << endl;
	
	return 0;
}
