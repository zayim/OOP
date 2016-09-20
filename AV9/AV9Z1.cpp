#include <iostream>
#include <cstring>
using namespace std;
struct sat
{
    int H,M;
    sat() { H=M=0; }
    sat(int h, int m) { H=h; M=m; }

    int h() { return H; }
    int m() { return M; }
    bool operator < (const sat &s) const
    {
        if (H < s.H) return true;
        else if (H == s.H && M<s.M) return true;
        else return false;
    }
    bool operator == (const sat &s) const { return (H==s.H && M==s.M); }
    bool operator > (const sat &s) const { return !(*this<s || *this==s); }
    int operator - (const sat &s) const
    {
        int m1=H*60+M,m2=s.H*60+s.M;
        return (m1-m2)/60;
    }
};
class zaposlenik
{
    int id,opterecenje,prekovremeni;
    double plata;
    string ime, prezime;
    int radni_sati;
    sat dolazak,odlazak;
    bool naPoslu;
    double obrok;

    public:
    zaposlenik(int ID, string i, string pr, double p, int o);
    int platniBroj() { return id; }
    void resetuj() { radni_sati=prekovremeni=obrok=0; dolazak=odlazak=sat(0,0); naPoslu=false; }
    bool jeLiNaPoslu() { return naPoslu; }
    void postaviDolazak(int h, int m) { dolazak=sat(h,m); }
    void postaviOdlazak(int h, int m) { odlazak=sat(h,m); }
    sat Dolazak() { return dolazak; }
    sat Odlazak() { return odlazak; }
    void dodji() { naPoslu=true; }
    void obracunaj();
    void otidji() { naPoslu=false; }
    int Prekovremeni() { return prekovremeni; }
    string Ime() { return ime; }
    string Prezime() { return prezime; }
    int NormalniSati() { return radni_sati; }
    int Opterecenje() { return opterecenje; }
    double Plata();
    double DodatakPrekovremeni();
    double Obrok() { return obrok; }
    double UkupanIznos();
};
zaposlenik::zaposlenik(int ID, string i, string pr, double p, int o)
{
    id=ID; ime=i; prezime=pr; plata=p; opterecenje=radni_sati=prekovremeni=obrok=0; naPoslu=false; dolazak=odlazak=sat(0,0);
}
void zaposlenik::obracunaj()
{
    if (odlazak>sat(16,0))
    {
        radni_sati+=sat(16,0)-dolazak;
        prekovremeni=odlazak-sat(16,0);
        obrok++;
    }
    else radni_sati+=odlazak-dolazak;
}
double zaposlenik::Plata()
{
    if (radni_sati>=opterecenje) return plata;
    double satnica=plata/40.;
    return (plata - satnica*(opterecenje-radni_sati));
}
double zaposlenik::DodatakPrekovremeni()
{
    double satnica=plata/40.;
    return prekovremeni*satnica*1.5;
}
class fakultet
{
    int brZap,maxBrZap,minSatObrok;
    double obrok;
    zaposlenik** niz;

    public:
    fakultet (int max, double obr, int min_sat);
    //destruktor
    //konstruktor kopije
    //preklopljeni operator dodjele
    void kreiraj_zaposlenika(int ID, string i, string pr, double p, int o);
    void dolazak(int ID, int h, int m);
    void odlazak(int ID, int h, int m);
    void ispisi_zaposlenika(int ID);
    void ispisi_kompletno();
    void zakljuci() { for (int i=0; i<brZap; i++) niz[i]->resetuj(); }
};
fakultet::fakultet(int max, double obr, int min_sat)
{
     maxBrZap=max; obrok=obr; minSatObrok=min_sat; brZap=0;
     niz=new zaposlenik*[maxBrZap];
}
void fakultet::kreiraj_zaposlenika(int ID, string i, string pr, double p, int o)
{
    if (brZap==maxBrZap) throw "Dostignut maksimalan broj zaposlenika!";
    for (int j=0; j<brZap; j++)
        if (niz[j]->platniBroj()==ID) throw "Postoji zaposlenik sa istim platnim brojem!";

    niz[brZap++]=new zaposlenik(ID,i,pr,p,o);
}
void fakultet::dolazak(int ID, int h, int m)
{
    if (sat(h,m)<sat(8,0) || sat(h,m)>sat(16,0)) throw "Greska!";
    int i;
    bool nasao=false;
    zaposlenik* zap;

    for (i=0; i<brZap; i++)
        if (niz[i]->platniBroj()==ID) { zap=niz[i]; nasao=true; break; }
    if (!nasao) throw "Greska!";
    if (zap->jeLiNaPoslu()) throw "Greska!";
    zap->dodji();

    zap->postaviDolazak(h,m);
}
void fakultet::odlazak(int ID, int h, int m)
{
    if (sat(h,m)<sat(8,0) || sat(h,m)>sat(20,0)) throw "Greska!";
    int i;
    bool nasao=false;
    zaposlenik* zap;

    for (i=0; i<brZap; i++)
        if (niz[i]->platniBroj()==ID) { zap=niz[i]; nasao=true; break; }
    if (!nasao) throw "Greska!";
    if (!zap->jeLiNaPoslu()) throw "Greska!";
    if (zap->Dolazak() > sat(h,m)) throw "Greska!";
    zap->postaviOdlazak(h,m);
    zap->obracunaj();
    zap->otidji();
}
void fakultet::ispisi_zaposlenika(int ID)
{
    int i;
    double obr=0.0;
    zaposlenik* zap;
    for (i=0; i<brZap; i++)
        if (niz[i]->platniBroj()==ID) { zap=niz[i]; break; }

    cout << "ZAPOSLENIK\n";
    cout << "Platni broj: " << zap->platniBroj() << endl;
    cout << "Ime: " << zap->Ime() << endl;
    cout << "Prezime: " << zap->Prezime() << endl;
    cout << "Broj normalnih sati: " << zap->NormalniSati() << endl;
    cout << "Prekovremeni: " << zap->Prekovremeni() << endl;
    cout << "Obrok: ";
    if (zap->Obrok() >= minSatObrok) obr=zap->Obrok()*obrok;
    cout << obr << endl;

}
void fakultet::ispisi_kompletno()
{
    cout << "ISPIS SVIH ZAPOSLENIKA" << endl;
    cout << "======================" << endl;
    for (int i=0; i<brZap; i++)
    {
        this->ispisi_zaposlenika(niz[i]->platniBroj());
        cout << "-----------------------" << endl;
    }
}
int main()
{
    int max,obr,min_sat,komanda=1;
    int pb,opt,h,m;
    string ime,prezime;
    double plata;
    try
    {
        cout << "Unesite maximalni broj zaposlenika, obrok i min. satnicu: "; cin >> max >> obr >> min_sat;
        fakultet f(max,obr,min_sat);

        cout << "Unesite komandu:\n1 unos\n2 dolazak\n3 odlazak\n4 ispis jednog\n5 ispis\n6 reset\n0 kraj: " << endl;
        cin >> komanda;
        while (komanda)
        {
            switch(komanda)
            {
                case 1:
                {
                    cout << "UNESITE: platni broj, ime, prezime, platu i opterecenje:\n";
                    cin >> pb >> ime >> prezime >> plata >> opt;
                    f.kreiraj_zaposlenika(pb,ime,prezime,plata,opt);
                    break;
                }
                case 2:
                {
                    cout << "UNESITE: platni broj, sate, minute:\n";
                    cin >> pb >> h >> m;
                    f.dolazak(pb,h,m);
                    break;
                }
                case 3:
                {
                    cout << "UNESITE: platni broj, sate, minute:\n";
                    cin >> pb >> h >> m;
                    f.odlazak(pb,h,m);
                    break;
                }
                case 4:
                {
                    cout << "UNESITE: platni broj: "; cin >> pb;
                    f.ispisi_zaposlenika(pb);
                    break;
                }
                case 5:
                {
                    f.ispisi_kompletno();
                    break;
                }
                case 6:
                {
                    f.zakljuci();
                    break;
                }
            }

            cout << "Unesite komandu:\n1 unos\n2 dolazak\n3 odlazak\n4 ispis jednog\n5 ispis\n6 reset\n0 kraj: " << endl;
            cin >> komanda;
        }

        cout << endl << endl << "Kraj programa!" << endl;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(...)
    {
        cout << "Negdje je doslo do greske..." << endl;
    }

    return 0;
}
