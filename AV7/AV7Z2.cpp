#include <iostream>
using namespace std;
struct Cvor
{
    double element;
    Cvor *veza;

    Cvor (double x) { element=x; veza=NULL; }
};
int main()
{
    Cvor *pocetak,*i;
    double tmp,A_SR=0.;
    int n=1,brojVecih=0;
    bool kraj=false;

    cout << "Unesi niz brojeva (0 za kraj): ";
    cin >> tmp;
    pocetak=new Cvor(tmp);
    i=pocetak;

    while (!kraj)
    {
        cin >> tmp;
        if (tmp!=0.)
        {
            i->veza=new Cvor(tmp);
            i=i->veza;
            A_SR+=tmp;
            n++;
        }
        else kraj=true;
    }
    A_SR/=n;

    for (i=pocetak; i!=NULL; i=i->veza)
    if (i->element>A_SR) brojVecih++;

    cout << "Broj elemenata vecih od A. SR.: " << brojVecih << endl;

    return 0;
}
