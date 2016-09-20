#include <iostream>
#define MAX 100
using namespace std;
int f1(int a[][MAX], int n)
{
    int rb=0,suma=0,maxsuma=0;
    for (int i=0; i<n; i++) maxsuma+=a[i][0];

    for (int i=1; i<n; i++)
    {
        suma=0;
        for (int j=0; j<n; j++) suma+=a[j][i];
        if (suma>maxsuma)
        {
            rb=i;
            maxsuma=suma;
        }
    }
    return rb;
}
int f2(int a[][MAX], int n)
{
    int rb=0,suma=0,minsuma=0;
    for (int i=0; i<n; i++) minsuma+=a[0][i];

    for (int i=1; i<n; i++)
    {
        suma=0;
        for (int j=0; j<n; j++) suma+=a[i][j];
        if (suma<minsuma)
        {
            rb=i;
            minsuma=suma;
        }
    }
    return rb;
}
int f3(int a[][MAX], int n)
{
    int suma=0;
    for (int i=0; i<n; i++) suma+=a[i][i];
    return suma;
}
int main()
{
    int n,a[MAX][MAX];

    cout << "Unesite n: "; cin >> n;
    cout << "Unesite matricu nxn: " << endl;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    cout << "\nINDEXI KRECU OD NULE!\n" << endl;
    cout << "Redni broj kolone sa najvecom  sumom: " << f1(a,n) << endl;
    cout << "Redni broj reda   sa najmanjom sumom: " << f2(a,n) << endl;
    cout << "Suma elemenata na dijagonali:         " << f3(a,n) << endl;
}
