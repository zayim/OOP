#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "TestCurenja.h"
using namespace std;
void KreirajMatricu(double **&dinamickaMatrica, int n)
{
    dinamickaMatrica=new double*[n];

    for (int i=0; i<n; i++) dinamickaMatrica[i]=0;
    try
    {
        for (int i=0; i<n; i++) dinamickaMatrica[i]=new double[n];
    }
    catch(bad_alloc e)
    {
        for (int i=0; i<n; i++) delete[] dinamickaMatrica[i];
        delete[] dinamickaMatrica;
        dinamickaMatrica=0;
        throw e;
    }
}
void UnesiMatricu(double **&dinamickaMatrica, int n)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            //cout << "i: " << i << " j:" << j;
            //system("PAUSE");
            cin >> dinamickaMatrica[i][j];

        }
}
double** SaberiMatrice(double **dM1, double **dM2, int n)
{
    double **zbir;
    KreirajMatricu(zbir,n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            zbir[i][j]=dM1[i][j]+dM2[i][j];
    return zbir;
}
void IspisiMatricu(double **dinamickaMatrica, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++) cout << setw(5) << dinamickaMatrica[i][j];
        cout << endl;
    }
}
void UnistiMatricu(double **dinamickaMatrica, int n)
{
    for (int i=0; i<n; i++) delete[] dinamickaMatrica[i];
    delete[] dinamickaMatrica;
}
int main()
{
    double **a=0,**b=0,**c=0;
    int n;

    cout << "Unesi dimenziju: "; cin >> n;

    try
    {
        cout << "Unesi 1. matricu nxn:" << endl;
        KreirajMatricu(a,n); UnesiMatricu(a,n);

        cout << "Unesi 2. matricu nxn:" << endl;
        KreirajMatricu(b,n); UnesiMatricu(b,n);

        c=SaberiMatrice(a,b,n);

        cout << "Zbir matrica: " << endl;
        IspisiMatricu(c,n);

        UnistiMatricu(a,n); UnistiMatricu(b,n); UnistiMatricu(c,n);
    }
    catch(...)
    {
        cout << "Problemi s memorijom!" << endl;
        if (a) UnistiMatricu(a,n);
        if (b) UnistiMatricu(b,n);
        if (c) UnistiMatricu(c,n);
    }

    return 0;
}
