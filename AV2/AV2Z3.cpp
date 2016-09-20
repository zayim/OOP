#include <iostream>
using namespace std;
double razlomak(double a[], int n)
{
    double razl=a[n-1];
    int i;

    for (i=n-2; i>=0; i--)
    {
        if (razl==0.0) throw "Jedan od nazivnika je nula!";
        razl=1./razl+a[i];
    }

    return razl;
}
int main()
{
    double a[100];
    int i,n;

    cout << "Unesite broj elemenata niza: "; cin >> n;
    cout << "Unesite elemente niza: ";
    for (i=0; i<n; i++) cin >> a[i];

    try
    {
        cout << "Vrijednost veriznog razlomka: " << razlomak(a,n) << endl;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }

    return 0;
}
