#include <iostream>
#include <cmath>
//#include "TestCurenja.h"
using namespace std;
int* fib(int n)
{
    if (n<=0) throw "Broj elemenata mora biti pozitivan!";
    int *niz;
    try
    {
        niz=new int[n];
    }
    catch(bad_alloc)
    {
        throw "Alokacija nije uspjela!";
    }

    niz[0]=1;
    for (int i=1; i<n; i++) niz[i]=2*niz[i-1];

    return niz;
}
int main()
{
    int n,*a;

    cout << "Unesite prirodan broj: "; cin >> n;

    try
    {
        a=fib(n);

        cout << "Prvih n stepena dvojke: ";
        for (int i=0; i<n; i++) cout << a[i] << " ";

        delete[] a;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(...)
    {
        cout << "Neki problemi! :S" << endl;
    }

    return 0;
}

