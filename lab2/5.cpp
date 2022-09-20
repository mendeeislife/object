#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 3, b = 5;

    cout << "Solihoos umnu" << endl;
    cout << "a = " << a << " b = " << b << endl;

    swap(a, b);

    cout << "Solisnii daraa" << endl;
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}