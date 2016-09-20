#include <iostream>
using namespace std;
bool mnozi(double a1[][20], double a2[][20], double a3[][20], int m1, int n1, int m2, int n2)
{
    int i,j,k,z=0;

    if (n1!=m2) return false;

    for (i=0; i<m1; i++)
    for (j=0; j<n2; j++)
    {
        z=0;
        for (k=0; k<n1; k++) z+=a1[i][k]*a2[k][j];
        a3[i][j]=z;
    }

    return true;
}
int main()
{
    double a1[20][20],a2[20][20],a3[20][20];
    int m1,n1,m2,n2,i,j;

    cout << "Dimenzije prve matrice? "; cin >> m1 >> n1;
    cout << "Prva matrica: " << endl;
    for (i=0; i<m1; i++)
    for (j=0; j<n1; j++) cin >> a1[i][j];

    cout << "Dimenzije druge matrice? "; cin >> m2 >> n2;
    cout << "Druga matrica: " << endl;
    for (i=0; i<m2; i++)
    for (j=0; j<n2; j++) cin >> a2[i][j];

    if (mnozi(a1,a2,a3,m1,n1,m2,n2))
    {
        cout << "Proizvod: " << endl;
        for (i=0; i<m1; i++)
        {
            for (j=0; j<n2; j++) cout << a3[i][j] << " ";
            cout << endl;
        }
    }
    else cout << "Matrice se ne mogu pomnoziti!" << endl;

}
