#include <iostream>
using namespace std;

int main() {
    int a = 125;
    int *p = &a;
    cout << p << endl;
    cout << *p << endl;
    p++;
    cout<<endl;
    cout << p << endl;
    cout << *p << endl;

    return 0;
}