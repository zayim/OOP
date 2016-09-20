#include <iostream>
#include <cstring>
//#include "TestCurenja.h"
using namespace std;
int main()
{
    string **niz(0),rijec,**sredina,**pocetak,**kraj;
    int i,n,j;
    bool ima=false;

    try
    {
        cout << "Unesite broj rijeci: "; cin >> n;
        niz=new string*[n];
        cout << "Unesite rijeci:" << endl;
        for (i=0; i<n; i++)
        {
            niz[i]=new string;
            cin >> *niz[i];
        }

        /// INSERTION SORT
        for (i=1; i<n; i++)
        {
            j=i;
            while (j>0 && *niz[j-1]<*niz[j]) { swap(niz[j],niz[j-1]); j--; }
        }
        ///

        cout << "Sortirane rijeci:" << endl;
        for (i=0; i<n; i++) cout << *niz[i] << endl;

        cout << "Unesite naknadno jos jednu rijec:" << endl; cin >> rijec;

        /// BINARY SEARCH
        pocetak=niz; kraj=niz+n; ima=false;
        while (pocetak<=kraj)
        {
            sredina=pocetak + (kraj-pocetak)/2;
            if (rijec < **sredina) pocetak=sredina+1;
            else if (rijec > **sredina) kraj=sredina-1;
            else { ima=true; break; }
        }
        ///

        cout << "Unesena rijec se " << (ima ? "" : "ne ") << "nalazi na spisku rijeci!" << endl;
    }
    catch(bad_alloc e)
    {
        cout << "Problemi s memorijom";
    }
    catch(...)
    {
        cout << "Negdje je doslo do grske :O";
    }

    for (i=0; i<n; i++) delete niz[i];
    delete[] niz; niz=0;

    return 0;
}
