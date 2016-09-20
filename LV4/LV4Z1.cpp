#include <iostream>
//#include "TestCurenja.h"
using namespace std;
double* f(double niz[], int n)
{
    double *dinamickiNiz=new double[n];

    for (int i=0; i<n; i++)
    {
        if (!niz[i])
        {
            delete[] dinamickiNiz;
            throw "Nazivnik ne smije biti nula!";
        }
        else dinamickiNiz[i]=1./niz[i];
    }

    return dinamickiNiz;
}
int main()
{
    double a[100],*b;
    int n;

    cout << "Unesite broj elemenata: "; cin >> n;
    cout << "Unesite niz realnih brojeva: ";
    for (int i=0; i<n; i++) cin >> a[i];

    try
    {
        b=f(a,n);

        cout << "Niz reciprocnih vrijednosti: ";
        for (int i=0; i<n; i++) cout << b[i] << " ";
        delete[] b;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(bad_alloc)
    {
        cout << "Problemi sa memorijom! :(" << endl;
    }
    catch(...)
    {
        cout << "Neki problemi! :S" << endl;
    }

    return 0;
}
