#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string niz[100],ispisane[100];
    int i,j,n,ispisano=0,min_ind,max_ind;
    bool daLiJeIspisana=false;

    cout << "Koliko rijeci? "; cin >> n;
    cout << "Unesi rijeci: " << endl;
    for (i=0; i<n; i++) cin >> niz[i];

    min_ind=max_ind=0;
    for (i=1; i<n; i++)
    {
        if (niz[i] > niz[max_ind]) max_ind=i;
        if (niz[i] < niz[min_ind]) min_ind=i;
    }

    cout << "Alfabetski prva rijec: " << niz[min_ind] << endl;
    cout << "Alfabetski zadnja rijec: " << niz[max_ind] << endl;

    cout << "Spisak (jedinstvenih) rijeci: " << endl;
    for (i=0; i<n; i++)
    {
        daLiJeIspisana=false;
        for (j=0; j<ispisano; j++)
            if (niz[i]==ispisane[j]) { daLiJeIspisana=true; break; }

        if (!daLiJeIspisana)
        {
            cout << niz[i] << endl;
            ispisane[ispisano++]=niz[i];
        }
    }

    return 0;
}
