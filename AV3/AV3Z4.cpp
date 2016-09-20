#include <iostream>
using namespace std;
template <typename Tip>
int BrojZajednickih(Tip *pocetak1, Tip *kraj1, Tip *pocetak2, Tip *kraj2)
{
    Tip *p,*q;
    bool ima=false;
    int bz=0;

    for (p=pocetak1; p!=kraj1; p++)
    {
        ima=false;
        for (q=pocetak1; q!=p; q++)
            if(*p == *q) { ima=true; break; }

        if (!ima)
        {
            ima=false;
            for (q=pocetak2; q!=kraj2; q++)
                if (*p==*q) { ima=true; break; }

            if (ima) bz++;
        }
    }

    return bz;
}
int main()
{
    int a[100],b[100],m,n,i;

    cout << "Unesite broj elemenata prvog niza: "; cin >> m;
    cout << "Unesite elemente prvog niza: ";
    for (i=0; i<m; i++) cin >> a[i];

    cout << "Unesite broj elemenata drugog niza: "; cin >> n;
    cout << "Unesite elemente drugog niza: ";
    for (i=0; i<n; i++) cin >> b[i];

    cout << "Broj zajednickih elemenata: " << BrojZajednickih(a,a+m,b,b+n) << endl;

    return 0;
}
