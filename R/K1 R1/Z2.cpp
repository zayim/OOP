#include <iostream>
//#include "TestCurenja.h"
using namespace std;
template <typename Tip>
bool simetricanBlok(Tip* pocetak, Tip* kraj)
{
    Tip *p,*sredina= pocetak+(kraj-pocetak)/2;

    for (p=pocetak; p!=sredina; p++)
        if (*p != * (pocetak+(kraj-p-1)) ) return false;

    return true;
}
int main()
{
    int niz[10],i;

    cout << "Unesi 10 cijelih brojeva: ";
    for (i=0; i<10; i++) cin >> niz[i];

    cout << "Blok " << (simetricanBlok(niz,niz+10) ? "jeste" : "nije") << " simetrican!" << endl;

    return 0;
}
