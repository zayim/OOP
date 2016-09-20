#include <iostream>
#include <iomanip>
#include <complex>
#include <string>
using namespace std;
void P1(int a, int b) {
    cout << a << b;
    a += 3; b *= 2;
    cout << a << b;
}
void P2(int &a, int &b) {
    cout << a << b;
    a += 3; b *= 2;
    cout << a << b;
}
int F1(int x) {
    return x + 1;
}
int F2(int x) {
    return 2 * x;
}
int main() {
    int a(2), b(5);

    cout << 3 << setw(3) << a << a * a << setw(5) << b * b << endl;
    complex<double> c = 3, i(0, 1);
    cout << c << c * c << " " << c * i << c + c * i << endl;

    P1(b, a);
    cout << a << b << endl;

    P2(b, a);
    cout << a << b << endl;
    string s = "abcdefghijklmnopqrstuvwxyz";

    cout << s.length() << s.size() << s.substr(0, 5) + s.substr(10, 3) << endl;

    int (*npf[5])(int) = {F1, F2, F1, F2, F2};
    int suma(0);

    for(int i = 0; i < 5; i++) suma += (i + 1) * npf[i](i);
    cout << suma;

    return 0;
}
