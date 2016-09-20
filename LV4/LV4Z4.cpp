#include <iostream>
#include <cmath>
//#include "TestCurenja.h"
using namespace std;
template <typename tip>
tip* f(tip niz[], int n)
{
    tip *dinamickiNiz=new tip[n];

    for (int i=0, j=n-1; i<n; i++, j--)
        dinamickiNiz[i]=niz[j];

    return dinamickiNiz;
}
int main()
{
    int n;
    double a[100],*b;

    cout << "Unesite broj elemenata niza: "; cin >> n;
    cout << "Unesite n realnih brojeva: ";
    for (int i=0; i<n; i++) cin >> a[i];

    try
    {
        b=f(a,n);

        cout << "Brojevi u obrnutom poretku: ";
        for (int i=0; i<n; i++) cout << b[i] << " ";

        delete[] b;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(bad_alloc)
    {
        cout << "Problemi sa memorijom! :(" << endl;
    }
    catch(...)
    {
        cout << "Neki problemi! :S" << endl;
    }

    return 0;
}
/*#include <iostream>
#include <cmath>
#include <vector>
//#include "TestCurenja.h"
using namespace std;
template <typename tip>
tip* f(vector<tip> v, int n)
{
    tip *dinamickiNiz=new tip[n];

    for (int i=0, j=n-1; i<n; i++, j--)
        dinamickiNiz[i]=v[j];

    return dinamickiNiz;
}
int main()
{
    int n;
    vector<double> a;
    double *b;

    cout << "Unesite broj elemenata vektora: "; cin >> n; a.resize(n);
    cout << "Unesite n realnih brojeva: ";
    for (int i=0; i<n; i++) cin >> a[i];

    try
    {
        b=f(a,n);

        cout << "Brojevi u obrnutom poretku: ";
        for (int i=0; i<n; i++) cout << b[i] << " ";

        delete[] b;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(bad_alloc)
    {
        cout << "Problemi sa memorijom! :(" << endl;
    }
    catch(...)
    {
        cout << "Neki problemi! :S" << endl;
    }

    return 0;
}
*/
