#include <iostream>
using namespace std;
template <typename Tip>
void alokacijaMatrice(Tip **&dinamickaMatrica, int n)
{
    dinamickaMatrica=0;
    int i,j;

    try
    {
        dinamickaMatrica=new Tip*[n];
        for (i=0; i<n; i++) dinamickaMatrica[i]=0;

        for (i=0; i<n; i++) dinamickaMatrica[i]=new Tip[n];
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
    int **dinamickaMatrica,i,j,n;

    cout << "Unesite n: "; cin >> n;

    try
    {
        alokacijaMatrice(dinamickaMatrica,n);

        cout << "Unesite neku matricu formata nxn: " << endl;
        for (i=0; i<n; i++)
        for (j=0; j<n; j++) cin >> dinamickaMatrica[i][j];

        cout << "Unesena matrica: " << endl;
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++) cout << dinamickaMatrica[i][j] << " ";
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
