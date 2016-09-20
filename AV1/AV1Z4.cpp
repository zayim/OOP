#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char niz[100][100],ispisane[100][100];
    int i,j,n,min_ind=0,max_ind=0,ispisano=0;
    bool daLiJeIspisana=false;

    cout << "Koliko rijeci? "; cin >> n;
    for (i=0; i<n; i++) cin >> niz[i];

    for (i=1; i<n; i++)
    {
        if (strcmp(niz[min_ind],niz[i])>0) min_ind=i;
        if (strcmp(niz[i],niz[max_ind])>0) max_ind=i;
    }

    cout << "Alfabetski prva rijec: " << niz[min_ind] << endl;
    cout << "Alfabetski zadnja rijec: " << niz[max_ind] << endl;

    cout << "Spisak (jedinstvenih) rijeci: " << endl;
    for (i=0; i<n; i++)
    {
        daLiJeIspisana=false;
        for (j=0; j<ispisano; j++)
            if (!strcmp(ispisane[j],niz[i])) { daLiJeIspisana=true; break; }

        if (!daLiJeIspisana)
        {
            cout << niz[i] << endl;
            strcpy(ispisane[ispisano++],niz[i]);
        }
    }

    return 0;
}
