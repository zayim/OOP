#include <iostream>
#include <algorithm>
using namespace std;
template <typename Tip>
bool JednakiBlokovi(Tip *pocetak1, Tip *kraj1, Tip *pocetak2)
{
    Tip *p;

    for (p=pocetak1; p<kraj1; p++) if (*p != *(pocetak2 + (p-pocetak1)) ) return false;
    return true;
}
int main()
{
    double a[100],b[100];
    int i,n;

    cout << "Unesi broj elemenata nizova: "; cin >> n;
    cout << "Unesi prvi niz: ";
    for (i=0; i<n; i++) cin >> a[i];
    cout << "Unesi drugi niz: ";
    for (i=0; i<n; i++) cin >> b[i];

    cout << "Funkcija 'JednakiBlokovi': " << endl;
    cout << (JednakiBlokovi(a,a+n,b) ? "Blokovi su jednaki!" : "Blokovi nisu jednaki!") << endl << endl;

    cout << "Funkcija 'equal': " << endl;
    cout << (equal(a,a+n,b) ? "Blokovi su jednaki!" : "Blokovi nisu jednaki!") << endl;

    return 0;
}
