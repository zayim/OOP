#include <iostream>
#include <cmath>
#define epsilon 0.0000001
#define PI 3.14159265358979323846
using namespace std;
double Integral(double (*f)(double), double a, double b, int n)
{
    double k=(b-a)/n, h=k/6., integral=0.;

    for (int i=0; i<=n; i++)
    {
        double xi=a + k*i;
        integral+=(f(xi) + 5*f(xi+h) + f(xi+2*h) + 6*f(xi + 3*h) + f(xi + 4*h) + 5*f(xi + 5*h) + f(xi + 6*h));
    }

    return 3.*h*integral/10.;
}
double x_na_3(double x) { return x*x*x; }
double x_reciprocno(double x) { return 1./x; }
int main()
{
    cout << "Integral(sin,0,PI): " << Integral(sin,0,PI,10000) << endl;
    cout << "Integral(x^3,0,10): " << Integral(x_na_3,0,10,1000000) << endl;
    cout << "Integral(1/x,1,2):  " << Integral(x_reciprocno,1,2,100000) << endl;

    return 0;
}
