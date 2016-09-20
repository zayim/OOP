#include <iostream>
#include <cmath>
#define MAX 100
using namespace std;
double f(double a[], int n)
{
    double izraz=0;

    for (int i=n-1; i>=0; i--)
    {
        izraz+=a[i];
        if (izraz<0) throw "Ne mozemo izracunati korijen negativnog broja!";
        izraz=sqrt(izraz);
    }

    return izraz;
}
int main()
{
    int n;
    double a[MAX],rez;

    cout << "Unesite n: "; cin >> n;
    cout << "Unesite elemente niza: ";
    for (int i=0; i<n; i++) cin >> a[i];

    try
    {
        rez=f(a,n);
        cout << "Vrijednost izraza: " << rez << endl;
    }
    catch (const char poruka[])
    {
        cout << poruka << endl;
    }
    catch (...)
    {
        cout << "Nesto nije uredu :(" << endl;
    }
}

