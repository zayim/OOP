#include <iostream>
#define MAX 100
using namespace std;
template <typename Tip>
void kronecker(Tip a[], Tip b[], int n, int m, Tip c[][MAX])
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            c[i][j]=a[i]*b[j];
}
int main()
{
    int a[MAX],b[MAX],n,m,c[MAX][MAX];

    cout << "Broj elemenata 1. niza: "; cin >> n;
    cout << "Elementi prvog niza: ";
    for (int i=0; i<n; i++) cin >> a[i];

    cout << "Broj elemenata 2. niza: "; cin >> m;
    cout << "Elementi drugog niza: ";
    for (int i=0; i<m; i++) cin >> b[i];

    kronecker(a,b,n,m,c);

    cout << "Kroneckerov produkt: " << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++) cout << c[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
