#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;
class Tim
{
    int brojOdigranih,brojPobjeda,brojPoraza,brojNerijesenih,brojDatih,brojPrimljenih,brojPoena;
    char ime[20];

    public:
    Tim(const char ime[]);
    void ObradiUtakmicu(int dati, int primljeni);
    const char* ImeTima() const { return ime; }
    int BrojPoena() const { return brojPoena; }
    int GolRazlika() const { return (brojDatih-brojPrimljenih); }
    void IspisiPodatke() const;
};
Tim::Tim(const char ime[]) : brojOdigranih(0),brojPobjeda(0),brojPoraza(0),brojNerijesenih(0),brojDatih(0),brojPrimljenih(0),brojPoena(0)
{
    strcpy(this->ime,ime);
}
void Tim::ObradiUtakmicu(int dati, int primljeni)
{
    brojOdigranih++; brojDatih+=dati; brojPrimljenih+=primljeni;
    if (dati<primljeni) brojPoraza++;
    else if (dati==primljeni) { brojNerijesenih++; brojPoena++; }
    else { brojPobjeda++; brojPoena+=3; }
}
void Tim::IspisiPodatke() const
{
    cout << ime;
    int brojPraznih=20 - strlen(ime);
    for (int i=0; i<brojPraznih; i++) cout << " ";
    cout << setw(4) << brojOdigranih << setw(4) << brojPobjeda << setw(4) << brojNerijesenih << setw(4) << brojPoraza;
    cout << setw(4) << brojDatih << setw(4) << brojPrimljenih << setw(4) << brojPoena << endl;

}
class Liga
{
    int brojTimova;
    const int maxBrojTimova;
    Tim **timovi;
    static bool poredi(const Tim *tim1, const Tim *tim2);

    public:
    explicit Liga(int velicinaLige);
    ~Liga() { for (int i=0; i<brojTimova; i++) delete timovi[i]; delete[] timovi; }
    void DodajNoviTim (const char imeTima[]);
    void RegistrirajUtakmicu (const char imeTima1[], const char imeTima2[], int rezultat1, int rezultat2);
    void IspisiTabelu();
};
Liga::Liga(int velicinaLige) : maxBrojTimova(velicinaLige), brojTimova(0)
{
    timovi = new Tim*[maxBrojTimova];
    for (int i=0; i<maxBrojTimova; i++) timovi[i]=NULL; // zbog sigurnosti stavljamo da su na pocetku svi elementi niza nul-pokazivaci...
}
void Liga::DodajNoviTim (const char imeTima[])
{
    if (brojTimova>=maxBrojTimova) throw "Liga je puna!";
    timovi[brojTimova++]=new Tim(imeTima);
}
void Liga::RegistrirajUtakmicu (const char imeTima1[], const char imeTima2[], int rezultat1, int rezultat2)
{
    bool ima=false;
    Tim *tim1=NULL, *tim2=NULL;
    for (int i=0; i<brojTimova; i++)
        if (!strcmp(timovi[i]->ImeTima(),imeTima1))
        {
            tim1=timovi[i]; ima=true;
            break;
        }
    if (!ima) throw "Nema tima sa zadanim imenom!";
    ima=false;
    for (int i=0; i<brojTimova; i++)
        if (!strcmp(timovi[i]->ImeTima(),imeTima2))
        {
            tim2=timovi[i]; ima=true;
            break;
        }
    if (!ima) throw "Nema tima sa zadanim imenom!";

    tim1->ObradiUtakmicu(rezultat1,rezultat2);
    tim2->ObradiUtakmicu(rezultat2,rezultat1);
}
void Liga::IspisiTabelu()
{
    sort(timovi,timovi+brojTimova,poredi);
    for (int i=0; i<brojTimova; i++) timovi[i]->IspisiPodatke();
}
bool Liga::poredi(const Tim *tim1, const Tim *tim2)
{
    if (tim1->BrojPoena() < tim2->BrojPoena()) return false;
    else if (tim1->BrojPoena() == tim2->BrojPoena())
    {
        if (tim1->GolRazlika() < tim2->GolRazlika()) return false;
        else return true;
    }
    else return true;
}
int main()
{
    try
    {
        Liga liga(6);
        liga.DodajNoviTim("Barcelona");
        liga.DodajNoviTim("RealMadrid");
        liga.DodajNoviTim("Bayern");
        liga.DodajNoviTim("Chelsea");
        liga.DodajNoviTim("Milan");
        liga.DodajNoviTim("Arsenal");

        char ime1[20],ime2[20];
        int rez1,rez2;
        bool kraj=false;

        cout << "Spisak timova" << endl << "1. Barcelona\n2. RealMadrid\n3. Bayern\n4. Chelsea\n5. Milan\n6. Arsenal" << endl;
        while (!kraj)
        {
            cout << "Unesite rezultat utakmice (format: ime1 ime2 golovi1 golovi2)\n[napisite \"kraj\" za kraj]" << endl;
            cin >> ime1;
            if (strcmp(ime1,"kraj")) { cin >> ime2 >> rez1 >> rez2; liga.RegistrirajUtakmicu(ime1,ime2,rez1,rez2); }
            else kraj=true;
        }

        cout << "TABELA" << endl;
        liga.IspisiTabelu();
    }
    catch (const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(bad_alloc e)
    {
        cout << "Problemi s memorijom!" << endl;
    }
    catch(...)
    {
        cout << "Negdje ima problema.. :O" << endl;
    }

    return 0;
}
