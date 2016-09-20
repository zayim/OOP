#include <iostream>
#include <algorithm>
using namespace std;
template <typename Tip>
bool f(const Tip& x)
{
    if (x>5) return true;
    else return false;
}
template <typename Tip>
void Zamijeni(Tip *p1, Tip *p2, bool (*f)(const Tip&), const Tip& v)
{
    Tip *p;
    for (p=p1; p<p2; p++) if (f(*p)) *p=v;
}
int main()
{
    double a[100];
    int i,n;

    cout << "Unesi broj elemenata niza: "; cin >> n;
    cout << "Unesi elemente niza: ";
    for (i=0; i<n; i++) cin >> a[i];

    Zamijeni(a,a+n,&f,0.0);

    cout << "Novi niz: ";
    for (i=0; i<n; i++) cout << a[i] << " ";

    return 0;
}
