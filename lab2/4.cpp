#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 3, b = 5;
    int *pa = &a, *pb = &b;

    cout << "Solihoos umnu" << endl;
    cout << "a = " << a << " b = " << b << endl;
    
    swap(pa, pb);
    
    cout << "Solisnii daraa" << endl;
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}