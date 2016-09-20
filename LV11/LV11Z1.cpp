#include <iostream>
#include <iomanip>
#include <cstring>
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
int main()
{
    Tim barca("Barcelona"), real("Real Madrid");
    barca.ObradiUtakmicu(5,0);
    real.ObradiUtakmicu(0,5);
    barca.IspisiPodatke();
    real.IspisiPodatke();

    return 0;
}
