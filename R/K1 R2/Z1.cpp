#include <iostream>
//#include "TestCurenja.h"
using namespace std;
int* stepeniDvojke(int n)
{
    if (n<=0) throw "Broj elemenata mora biti pozitivan";

    try
    {
        int *niz=new int[n],*p=niz,stepen=1;

        for (int i=0; i<n; i++, p++)
        {
            *p=stepen;
            stepen *= 2;
        }

        return niz;
    }
    catch(bad_alloc e)
    {
        throw "Alokacija nije uspjela";
    }
}
int main()
{
    int *niz(0),*p,i,n;

    cout << "Unesi n: "; cin >> n;
    try
    {
        p=niz=stepeniDvojke(n);
        cout << "Prvih n stepena dvojke: ";
        for (i=0; i<n; i++, p++) cout << *p << " ";
    }
    catch (const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(...)
    {
        cout << "Nesto ne valja :@" << endl;
    }

    delete[] niz;

    return 0;
}
