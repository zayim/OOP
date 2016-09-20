#include <iostream>
using namespace std;
template <typename Tip>
void MinMax(Tip *p1, Tip *p2, Tip &min, Tip &max)
{
    Tip *p;
    min=max=*p1;

    for (p=p1+1; p<p2; p++)
    {
        if (*p > max) max=*p;
        if (*p < min) min=*p;
    }
}
int main()
{
    double a[100],min,max;
    int i,n;

    cout << "Unesi broj elemenata niza: "; cin >> n;
    cout << "Unesi elemente niza: ";
    for (i=0; i<n; i++) cin >> a[i];

    MinMax(a,a+n,min,max);

    cout << "Minimalni element: " << min << endl;
    cout << "Maximalni element: " << max << endl;

    return 0;
}
