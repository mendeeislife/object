#include <iostream>
using namespace std;

int main() {
    int a = 125;
    int *p = &a;
    cout << p;
    cout << *p;
    p++;
    cout << p;
    cout << *p;

    return 0;
}