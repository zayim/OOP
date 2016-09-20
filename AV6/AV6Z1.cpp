#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;
const char s(' ');
void F1(int &a, int b, int &c) {
    a = b + c; b = a + c; c = a + b;
    cout << a << s << b << s << c << s;
}
void F2(int a, int &b, int c) {
    a = b + c; b = a + c; c = a + b;
    cout << a << s << b << s << c << s;
}
int &F3(double (*f)(double), int *p) {
    p[1] = int(f(*p)); return *(--p);
}
int main() {
    int x(4);

    F1(x, x, x);
    cout << x << endl;
    x = 4;

    F2(x, x, x);
    cout << x << endl;
    int a1(5);
    int a2(a1);
    const int a3(a1);
    int &a4(a1);
    const int &a5(a1);
    const int &a6(a1 + 0);
    a1 += 2;
    cout << a1 << a2 << a3 << a4 << a5 << a6 << endl;

    double c1(9);
    complex<double> c2(c1), c3(-c2);
    cout << sqrt(c1) << setw(7) << sqrt(c2) << " " << sqrt(c3) << endl;

    int niz[5] = {3, 7, 4, 5, 2};
    F3(sqrt, niz + 2)++;

    for(int i = 0; i < 5; i++) cout << niz[i] << " ";

    return 0;
}
