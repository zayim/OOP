#include <iostream>
//#include "TestCurenja.h"
using namespace std;
int* dinamickiNiz(int niz[], int n)
{
    if (n<=0) throw "Broj elemenata mora biti pozitivan";
    try
    {
        int *pok=new int[n],*p=pok;
        for (int i=0; i<n; i++, p++) *p=niz[i];
        return pok;
    }
    catch(bad_alloc e)
    {
        throw "Alokacija nije uspjela";
    }
}
int main()
{
    int niz[10],*pocetak(0),*p,*kraj,i;

    cout << "Unesi niz od 10 cijelih brojeva: ";
    for (i=0; i<10; i++) cin >> niz[i];

    try
    {
        pocetak=dinamickiNiz(niz,10); kraj=pocetak+10;
        cout << "Dinamicki alociran niz: ";
        for (p=pocetak; p!=kraj; p++) cout << *p << " ";
    }
    catch (const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(...)
    {
        cout << "Negdje je doslo do greske :(" << endl;
    }

    delete[] pocetak; p=pocetak=kraj=0;

    return 0;
}
