#include <iostream>
#include <cmath>
//#include "TestCurenja.h"
using namespace std;
int* fib(int n)
{
    int *niz=new int[n];

    niz[0]=1; if (n==1) return niz;
    niz[1]=1; if (n==2) return niz;

    for (int i=2; i<n; i++)
        niz[i]=niz[i-1]+niz[i-2];

    return niz;
}
void sredine(int niz[], int n, double &AS, double &GS, double &HS)
{
    AS=HS=0.; GS=1.;

    for (int i=0; i<n; i++)
    {
        AS+=niz[i];
        HS+=1./niz[i];
        GS*=niz[i];
    }

    AS/=n;
    HS=n/HS;
    GS=pow(GS,1./n);
}
int main()
{
    int n,*a;
    double aritm,geom,harm;

    cout << "Unesite prirodan broj: "; cin >> n;

    try
    {
        a=fib(n);

        cout << "Prvih n fibonacijevih brojeva: ";
        for (int i=0; i<n; i++) cout << a[i] << " ";
        cout << endl;

        sredine(a,n,aritm,geom,harm);

        cout << "Aritmeticka sredina:  " << aritm << endl;
        cout << "Geometrijska sredina: " << geom << endl;
        cout << "Harmonijska sredina:  " << harm << endl;

        delete[] a;
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

