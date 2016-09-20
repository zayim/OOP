#include <iostream>
#include <iomanip>
using namespace std;
int** Pascal (int n)
{
    if (n<=0) throw "Broj elemenata mora biti pozitivan";

    int** matrica=0,i,j;

    try
    {
        matrica=new int*[n];
        for (i=0; i<n; i++) matrica[i]=0;
        for (i=0; i<n; i++)
        {
            matrica[i]=new int[i+1];
            matrica[i][0]=matrica[i][i]=1;
            for (j=1; j<i; j++) matrica[i][j]=matrica[i-1][j-1]+matrica[i-1][j];
        }
    }
    catch(bad_alloc e)
    {
        if (matrica)
        {
            for (i=0; i<n; i++) delete[] matrica[i];
            delete[] matrica;
        }
        throw "Alokacija nije uspjela";
    }

    return matrica;
}
int main()
{
    int **pascal,i,j,n;

    cout << "Unesite n: "; cin >> n;

    try
    {
        pascal=Pascal(n);

        cout << "Paskalov trougao za n: " << endl;
        for (i=0; i<n; i++)
        {
            for (j=0; j<=i; j++) cout << setw(5) << pascal[i][j];
            cout << endl;
        }

        for (i=0; i<n; i++) delete[] pascal[i];
        delete[] pascal;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }

    return 0;
}
