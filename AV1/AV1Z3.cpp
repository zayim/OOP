#include <iostream>
#define MAX 100
using namespace std;
template <typename tip>
double tragMatrice(tip a[MAX][MAX], int n)
{
    int i,kraj=min(MAX,n),trag=0;

    for (i=0; i<kraj; i++) trag+=a[i][i];
    return trag;
}
template <typename tip>
bool daLiJeGornjaTrougaona(tip a[MAX][MAX], int n)
{
    int i,j,kraj=min(MAX,n);

    for (i=1; i<kraj; i++)
    for (j=0; j<i; j++)
        if (a[i][j]) return false;

    return true;
}
template <typename tip>
void transpozicija(tip a[MAX][MAX], int n)
{
    int i,j,kraj=min(MAX,n);

    for (i=1; i<kraj; i++)
    for (j=0; j<i; j++)
        swap(a[i][j],a[j][i]);
}

int main()
{
    double a[MAX][MAX];
    int i,j,n;

    cout << "Unesi dimenziju kvadratne matrice: "; cin >> n;
    cout << "Unesi matricu: " << endl;
    for (i=0; i<n; i++)
    for (j=0; j<n; j++) cin >> a[i][j];

    cout << "Trag: " << tragMatrice(a,n) << endl;
    cout << "Matrica" << (daLiJeGornjaTrougaona(a,n)? " jeste " : " nije ") << "gornja trougaona!" << endl;

    transpozicija(a,n);

    cout << "Transponovana matrica:" << endl;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++) cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}
