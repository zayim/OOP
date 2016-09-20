#include <iostream>
#define MAX 100
#include <iomanip>
#include <cstdlib>
using namespace std;
void popuni(int a[][MAX], int n)
{
    //a={};
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            a[i][j]=0;
    int k=1,kvadrat=n*n;
    int smjer=1; // 1-desno, 2-dole, 3-lijevo, 4-gore
    int i=0,j=0;

    while (k<=kvadrat)
    {
        if (smjer==1)
        {
            while (j<n && !a[i][j]) a[i][j++]=k++;
            j--; i++;
        }
        else if (smjer==2)
        {
            while (i<n && !a[i][j]) a[i++][j]=k++;
            i--; j--;
        }
        else if (smjer==3)
        {
            while (j>=0 && !a[i][j]) a[i][j--]=k++;
            j++; i--;
        }
        else if (smjer==4)
        {
            while (i>=0 && !a[i][j]) a[i--][j]=k++;
            i++; j++;
        }
        smjer++;
        if (smjer>4) smjer=1;
    }
}
int main()
{
    int a[MAX][MAX],n;

    cout << "Unesi n: "; cin >> n;
    popuni(a,n);

    cout << "Popunjena matrica: " << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }

}
