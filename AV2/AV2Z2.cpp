#include <iostream>
using namespace std;
double razlomak(double a[100], int n)
{
    double nazivnik=0.0,suma=0.0;
    int i;

    for (i=0; i<n; i++)
    {
        nazivnik+=a[i];
        if (nazivnik==0.0) throw "Jedan od nazivnika je nula!";
        suma+=1./nazivnik;
    }

    return suma;
}
int main()
{
    int n,i;
    double a[100];

    cout << "Unesite broj elemenata niza: "; cin >> n;
    cout << "Unesite elemente niza: ";
    for (i=0; i<n; i++) cin >> a[i];

    try
    {
        cout << "Vrijednost razlomka: " << razlomak(a,n) << endl;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }

    return 0;
}
