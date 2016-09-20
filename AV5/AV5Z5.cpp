#include <iostream>
using namespace std;
template <typename Tip>
Tip f_n(Tip x, Tip (*f)(Tip), int n)
{
    Tip vrijednost=x;
    for (int i=0; i<n; i++) vrijednost=f(vrijednost);
    return vrijednost;
}
int BrojDjelioca(int n)
{
    int broj=2;

    for (int i=2; i<n; i++)
        if (n%i==0) broj++;

    return broj;
}
int main()
{
    int x,n;

    cout << "Unesi cijele brojeve x i n: "; cin >> x >> n;
    cout << "f_n(x) = " << f_n(x,BrojDjelioca,n) << endl;

    return 0;
}
