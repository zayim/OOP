#include <iostream>
#define MAX 100
using namespace std;
template <typename Tip>
Tip* Nadji(Tip *p1, Tip *p2, bool (*f)(Tip))
{
    Tip *p=p1;

    for (p=p1; p<p2; p++)
        if (f(*p)) return p;

    return p2;
}
bool DaLiJeParan (int n)
{
    return !(n%2);
}
int main()
{
    int niz[MAX],n,i,*pok;

    cout << "Unesi n: "; cin >> n;
    cout << "Unesi n cijelih brojeva: ";
    for (i=0; i<n; i++) cin >> niz[i];

    pok=Nadji(niz,niz+n,DaLiJeParan);

    if (pok!=niz+n) cout << "Prvi paran broj u nizu: " << *pok << " (pozicija: " << (pok-niz)+1 << ")" << endl;
    else cout << "U nizu nema parnih brojeva!" << endl;

    return 0;
}
