#include <iostream>
using namespace std;
template <typename Tip>
Tip* NajveciElement (Tip *p1, Tip *p2, bool (*f)(Tip,Tip))
{
    Tip *max=p1,*p;

    for (p=p1+1; p<p2; p++)
        if (f(*max,*p)) max=p;

    return max;
}
inline int abs(int n) { return (n>0 ? n : -n); }
int SumaCifara(int n)
{
    int suma=0, tmp=abs(n);

    while (tmp>0)
    {
        suma+=tmp%10;
        tmp/=10;
    }

    return suma;
}
bool VecaSumaCifara(int a, int b) { return SumaCifara(b) > SumaCifara(a); }
int main()
{
    int i,niz[10];

    cout << "Unesite niz od 10 cijelih brojeva: ";
    for (i=0; i<10; i++) cin >> niz[i];

    cout << "Broj sa najvecom sumom cifara: " << * (NajveciElement(niz,niz+10,VecaSumaCifara)) << endl;
    return 0;
}
