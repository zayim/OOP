#include <iostream>
#include <vector>
using namespace std;
template <typename Tip>
Tip** alokacijaMatrice(vector<vector<Tip> > x)
{
    int i,j;
    int m=x.size(),n=0;
    Tip** dinamickaMatrica=0;

    try
    {
        dinamickaMatrica=new Tip*[m];
        for (i=0; i<m; i++) dinamickaMatrica[i]=0;

        for (i=0; i<m; i++)
        {
            dinamickaMatrica[i]=new Tip[x[i].size()];
            n=x[i].size();
            for (j=0; j<n; j++) dinamickaMatrica[i][j]=x[i][j];
        }
    }
    catch(bad_alloc e)
    {
        if (dinamickaMatrica)
        {
            for (i=0; i<m; i++) delete[] dinamickaMatrica[i];
            delete[] dinamickaMatrica;
        }

        throw "Kreiranje nije uspjelo";
    }

    return dinamickaMatrica;
}
int main()
{
    vector<vector<int> > v(3);
    int **dinamickaMatrica=0,i,j,tmp;

    cout << "Unesite elemente matrice 3x3: " << endl;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
        {
            cin >> tmp;
            v[i].push_back(tmp);
        }

    try
    {
        dinamickaMatrica=alokacijaMatrice(v);

        cout << "Unesena matrica: " << endl;
        for (i=0; i<3; i++)
        {
            for (j=0; j<3; j++) cout << dinamickaMatrica[i][j] << " ";
            cout << endl;
        }

        for (i=0; i<3; i++) delete[] dinamickaMatrica[i];
        delete[] dinamickaMatrica;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }

    return 0;
}
