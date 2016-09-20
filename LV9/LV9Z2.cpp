#include <iostream>
#include <string>
using namespace std;
struct Cvor
{
    string lokacija;
    int cijena, kvadratura;
    Cvor *veza;

    Cvor(string l, int c, int k, Cvor *v) { lokacija=l; cijena=c; kvadratura=k; veza=v; }
};
bool manjiCvor(const Cvor *c, int cijena, int kvadratura)
{
    if (c->cijena<cijena) return true;
    else if (c->cijena==cijena) return (c->kvadratura>kvadratura);
    else return false;
}
int main()
{
    string lokacija;
    int cijena, kvadratura;
    bool kraj=false;
    Cvor *pocetak=NULL,*pomocni,*i;

    cout << "Lokacija:   ";
    getline(cin,lokacija);

    if (lokacija.length()!=0)
    {
        cout << "Cijena:     "; cin >> cijena;
        cout << "Kvadratura: "; cin >> kvadratura;
        cout << endl;
        pocetak=new Cvor(lokacija,cijena,kvadratura,NULL);
    }
    else kraj=true;


    while (!kraj)
    {
        cout << "Lokacija:   ";
        cin.ignore(); cin.clear();
        getline(cin,lokacija);

        if (lokacija.length()!=0)
        {
            cout << "Cijena:     "; cin >> cijena;
            cout << "Kvadratura: "; cin >> kvadratura;
            cout << endl;
            i=pocetak;
            while (manjiCvor(i,cijena,kvadratura) && i->veza!=NULL) i=i->veza;
            if(i->veza==NULL && manjiCvor(i,cijena,kvadratura)) { i->veza=new Cvor(lokacija,cijena,kvadratura,NULL); cout << "kraj" << endl; }
            else
            {
                pomocni = new Cvor(i->lokacija,i->cijena,i->kvadratura,i->veza);
                i->lokacija=lokacija; i->cijena=cijena;
                i->kvadratura=kvadratura; i->veza=pomocni;
            }
        }
        else kraj=true;
    }

    cout << endl << "ISPIS" << endl;
    if (pocetak!=NULL)
        for (i=pocetak; i!=NULL; i=i->veza)
        {
            cout << "Lokacija:   " << i->lokacija << endl;
            cout << "Cijena:     " << i->cijena << endl;
            cout << "Kvadratura: " << i->kvadratura << endl << endl;
        }

    delete i; delete pomocni; delete pocetak;
    return 0;
}
