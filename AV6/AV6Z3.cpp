#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846
#define epsilon 0.000001
#define INTEGRAL_SIN 2.0
#define INTEGRAL_X_NA_3 2500.0
#define INTEGRAL_1_KROZ_X log(2)
using namespace std;
double Integral(double a, double b, double (*f)(double), int n)
{
    if (n%2) throw "n mora biti paran!";

    double h=(b-a)/n, sumaParnih=0.0, sumaNeparnih=0.0;
    int i;

    for (i=1; i<=n-1; i+=2) sumaNeparnih+=f(a+i*h);
    for (i=2; i<=n-2; i+=2) sumaParnih+=f(a+i*h);

    return h/3. * f(a) + h/3. * f(b) + h * 4./3. * sumaNeparnih + h * 2./3. * sumaParnih;
}
double x_na_3(double x) { return x*x*x; }
double x_reciprocno(double x) { return 1./x; }
int main()
{
    int n=2;

    while (fabs(Integral(0,PI,sin,n) - INTEGRAL_SIN)>=epsilon) n+=2;
    cout << "Integral sin(x) na (0,PI): " << Integral(0,PI,sin,n) << endl;
    cout << "n: " << n << endl << endl;

    n=2;
    while (fabs(Integral(0,10,x_na_3,n) - INTEGRAL_X_NA_3) >=epsilon) n+=2;
    cout << "Integral x^3 na (0,10): " << Integral(0,10,x_na_3,n) << endl;
    cout << "n: " << n << endl << endl;

    n=2;
    while (fabs(Integral(1,2,x_reciprocno,n) - INTEGRAL_1_KROZ_X) >=epsilon) n+=2;
    cout << "Integral 1/x na (1,2): " << Integral(1,2,x_reciprocno,n) << endl;
    cout << "n: " << n << endl << endl;

    return 0;
}
