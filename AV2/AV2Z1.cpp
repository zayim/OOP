#include <iostream>
using namespace std;
//int n; -> ovo rješenje sa globalnom promjenjivom koja cuva br. elemenata je cesto korišteno na vjezbama, medjutim nije preporucljivo...
void cifre(int a[], int n, int &bp, int &bn) // ovdje je funkciji dodan još jedan parametar, broj elemenata niza, bolje to nego globalna promjenjiva..
{
    bp=bn=0;
    int i,j,tmp,bc=0;

    for (i=0; i<n; i++)
    {
        if (a[i]<0) throw "Funkcija je predvidjena za rad sa pozitivnim brojevima!";
        bc=0; tmp=a[i];
        while (tmp>0) { bc++; tmp/=10; }

        if (bc%2) bn++;
        else bp++;

    }
}
int main()
{
    int n; // ako bismo koristili rješenje sa globalnom promjenjivom (što nije preporuèljivo), ova linija nam ne bi trebala...
    int i,a[100],bp,bn;

    cout << "Unesi broj elemenata niza: "; cin >> n;
    cout << "Unesi elemente niza: ";
    for (i=0; i<n; i++) cin >> a[i];

    try
    {
        cifre(a,n,bp,bn);
        cout << "Broj elemenata sa parnim brojem cifara:   " << bp << endl;
        cout << "Broj elemenata sa neparnim brojem cifara: " << bn << endl;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }

    return 0;
}
