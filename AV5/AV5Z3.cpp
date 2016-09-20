#include <iostream>
using namespace std;
template <typename Tip>
void alokacijaMatrice(Tip **&dinamickaMatrica, int n, int m)
{
    dinamickaMatrica=0;
    int i,j;

    try
    {
        dinamickaMatrica=new Tip*[n];
        for (i=0; i<n; i++) dinamickaMatrica[i]=0;

        for (i=0; i<n; i++)
        {
            dinamickaMatrica[i]=new Tip[m];
            for (j=0; j<m; j++) dinamickaMatrica[i][j]=Tip();
        }
    }
    catch(bad_alloc e)
    {
        if (dinamickaMatrica)
        {
            for (i=0; i<n; i++) delete[] dinamickaMatrica[i];
            delete[] dinamickaMatrica;
        }

        throw "Kreiranje nije uspjelo";
    }
}
int main()
{
    double **dinamickaMatrica;
    int i,j,n,m;

    cout << "Unesite n i m: "; cin >> n >> m;

    try
    {
        alokacijaMatrice(dinamickaMatrica,n,m);

        cout << "Popunjena matrica: " << endl;
        for (i=0; i<n; i++)
        {
            for (j=0; j<m; j++) cout << dinamickaMatrica[i][j] << " ";
            cout << endl;
        }

        for (i=0; i<n; i++) delete[] dinamickaMatrica[i];
        delete[] dinamickaMatrica;
    }
    catch (const char poruka[])
    {
        cout << poruka << endl;
    }

    return 0;
}

