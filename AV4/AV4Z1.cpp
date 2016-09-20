#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;
void F1(int a, int b) {
    a = b + 3; b = a - 1;
    cout << a << b;
}
void F2(int &a, int &b) {
    a = b + 3; b = a - 1;
    cout << a << b;
}
int *F3(int a, int *b) {
    cout << (*b)++;
    return new int(a);
}
int main() {
    int x(4);
    complex<double> c(4), i(0, 1);
    cout << setw(5) << c * c << c * i << setw(9) << c * i - c << endl;
    F1(x, x);
    cout << x << endl;
    F2(x, x);
    cout << x << endl;
    *F3(x, &x) = 7;
    cout << x << endl;
    return 0;
}
