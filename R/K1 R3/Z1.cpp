#include <iostream>
#define MAX 100
using namespace std;
int DuzinaStringa(char niz[]) // vjerovatno se moze koristiti i funkcija strlen umjesto ove, ali za svaki slucaj...
{
    int duzina=-1;
    while(niz[++duzina]);
    return duzina;
}
template <typename Tip>
void Razmijeni (Tip &a, Tip &b)
{
    Tip tmp=a;
    a=b;
    b=tmp;
}
void IzvrniTekst(char niz[])
{
    char *p,*q;

    for (p=niz, q=niz+DuzinaStringa(niz)-1; p<q; p++, q--) Razmijeni(*p,*q);
}
int main()
{
    char niz[MAX];

    cout << "Unesi niz znakova: "; cin >> niz;
    IzvrniTekst(niz);
    cout << "Izvrnut niz: " << niz << endl;

    return 0;
}
