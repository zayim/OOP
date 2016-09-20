#include <iostream>
#include <string>
using namespace std;
class Obrok
{
    protected:
    string naziv;
    double cijena;
    int index;

    public:
    Obrok(string N, double C, int I) { naziv=N; cijena=C; index=I; }
    string vratiNaziv() { return naziv; }
    double vratiCijenu() { return cijena; }
    int vratiIndex() { return index; }
    virtual void ispisi() { cout << "NAZIV: " << naziv << "\nCIJENA: " << cijena << "\nINDEX: " << index << endl; }
    virtual double ukupnaCijena() { return cijena; }
    virtual Obrok* kopijaObjekta() { Obrok* kopija = new Obrok(*this); return kopija; }

};
class ObrokSaPicem : public Obrok
{
    string nazivPica;
    double cijenaPica;

    public:
    string vratiNazivPica() { return nazivPica; }
    double vratiCijenuPica() { return cijenaPica; }
    ObrokSaPicem(string N, double C, int I, string NP, double CP)  : Obrok(N,C,I) { nazivPica=NP; cijenaPica=CP; }
    double ukupnaCijena() { return cijena + cijenaPica; }
    void ispisi() { cout << "NAZIV: " << naziv << " + " << nazivPica << "\nCIJENA: " << cijena+cijenaPica << "\nINDEX: " << index << endl; }
    Obrok* kopijaObjekta() { Obrok* kopija = new ObrokSaPicem(*this); return kopija; }
};
class Narudzbe
{
    Obrok **niz;
    int brojObroka;
    int maxBr;

    public:
    Narudzbe(int n);
    ~Narudzbe();
    Narudzbe(const Narudzbe &n);
    Narudzbe& operator=(const Narudzbe &n);
    void dodajObrok(string N, double C, int I);
    void dodajObrokSaPicem(string N, double C, int I, string NP, double CP);
    void ispisiPrvu();
    bool prazan() { return !brojObroka; }
    double operator[](int index);
};
Narudzbe::Narudzbe(int n) : maxBr(n), brojObroka(0)
{
    niz = new Obrok* [maxBr];
    for (int i=0; i<maxBr; i++) niz[i]=NULL;
}
Narudzbe::~Narudzbe()
{
    for (int i=0; i<brojObroka; i++) delete niz[i];
    delete[] niz;
}
Narudzbe::Narudzbe(const Narudzbe &n) : maxBr(n.maxBr)
{
    if (brojObroka<n.brojObroka)
    {
        for(int i=0; i<brojObroka; i++) delete niz[i];
        delete[] niz;
        niz = new Obrok*[maxBr];
    }
    brojObroka=n.brojObroka;

    for (int i=0; i<brojObroka; i++) niz[i] = n.niz[i]->kopijaObjekta();
}
Narudzbe& Narudzbe::operator=(const Narudzbe &n)
{
    maxBr=n.maxBr;
    if (brojObroka<n.brojObroka)
    {
        for(int i=0; i<brojObroka; i++) delete niz[i];
        delete[] niz;
        niz = new Obrok*[maxBr];
    }
    brojObroka=n.brojObroka;

    for (int i=0; i<brojObroka; i++) niz[i] = n.niz[i]->kopijaObjekta();

    return (*this);
}
void Narudzbe::dodajObrok(string N, double C, int I)
{
    if (brojObroka>=maxBr) throw "Ne moze!";

    niz[brojObroka++]=new Obrok(N,C,I);
}
void Narudzbe::dodajObrokSaPicem(string N, double C, int I, string NP, double CP)
{
    if (brojObroka>=maxBr) throw "Ne moze!";

    niz[brojObroka++]=new ObrokSaPicem(N,C,I,NP,CP);
}
void Narudzbe::ispisiPrvu()
{
    if (!brojObroka) throw "Nema!";
    niz[0]->ispisi();
    delete niz[0];
    for (int i=0; i<brojObroka-1; i++) niz[i]=niz[i+1];
    niz[--brojObroka]=0;
}
//mreze_:;
double Narudzbe::operator[](int index)
{
    double zbir=0.;
    for (int i=0; i<brojObroka; i++)
        if (niz[i]->vratiIndex()==index) zbir+=niz[i]->ukupnaCijena();

    return zbir;
}
int main()
{
    try
    {
        Narudzbe n(400000000);


        n.dodajObrok("Burek",2.5,4818);
        n.dodajObrokSaPicem("Cevapi",5.0,4818,"Coca Cola",2.5);
        n.dodajObrok("Sirnica",3.2,4812);
        n.dodajObrok("Pizza",4.0,4819);
        n.dodajObrokSaPicem("Grah",5.5,4825,"Kiseljak",1.0);
        cout << n[4818] << endl;
        while(!n.prazan()) n.ispisiPrvu();
        /*n.ispisiPrvu();
        */
        int x; cin >> x;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(bad_alloc)
    {
        cout << "Memorija!" << endl;
    }
    catch(...)
    {
        cout << "Nesto trece..." << endl;
    }


    return 0;
}
