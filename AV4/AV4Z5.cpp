#include <iostream>
#include <cmath>
using namespace std;
bool JeLiProst(int n)
{
    if (n==2) return true;
    if (!(n%2)) return false;
    if (n==1) return false;

    int i;
    int korijen=int(sqrt(n));
    for (i=3; i<=korijen; i+=2)
        if (!(n%i)) return false;

    return true;
}
int* prosti(int n)
{
    if (n<=0) throw "Parametar ne moze biti <= 0 !";

    try
    {
        int *pocetak=new int[n];
        int broj=3,bp=1;
        *pocetak=2;

        while (bp<n)
        {
            if (JeLiProst(broj)) *(pocetak + bp++)=broj;
            broj+=2;
        }

        return pocetak;
    }
    catch(bad_alloc e)
    {
        throw "Kreiranje niza nije uspjelo !";
    }
}
int main()
{
    int n,*p,*pok=0;

    cout << "Unesi n: "; cin >> n;

    try
    {
        cout << "Prvih n prostih brojeva: ";
        pok=prosti(n);
        for (p=pok; p!=pok+n; p++) cout << *p << " ";
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }

    delete[] pok;

    return 0;
}
