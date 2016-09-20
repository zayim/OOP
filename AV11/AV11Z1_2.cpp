#include <iostream>
#include <cstdlib>
using namespace std;
bool porediDvaCijelaBroja(const int &a, const int &b) { return a<=b; }
template <typename Tip>
class cvor
{
    public:
    cvor *prethodni, *sljedeci;
    Tip vrijednost;

    public:
    cvor() { prethodni=sljedeci=0; vrijednost=Tip(); }
    cvor (const Tip &vrijednost) { this->vrijednost=vrijednost; }
    cvor (const Tip &vrijednost, cvor *prethodni, cvor *sljedeci);
    void postaviVrijednost(const Tip &element) { vrijednost=element; }
    void postaviPrethodni(cvor *cvor1) { prethodni=cvor1; }
    void postaviSljedeci(cvor *cvor1) { sljedeci=cvor1; }
    Tip vratiVrijednost() { return vrijednost; }
    cvor* vratiPrethodni() { return prethodni; }
    cvor* vratiSljedeci() { return sljedeci; }
};
template <typename Tip>
cvor<Tip>::cvor (const Tip &vrijednost, cvor<Tip> *prethodni, cvor<Tip> *sljedeci)
{
    this->vrijednost=vrijednost;
    this->prethodni=prethodni;
    this->sljedeci=sljedeci;
}

template <typename Tip>
class red
{
    protected:
    cvor<Tip> *prvi,*zadnji;
    int brojElemenata;

    public:
    red() { brojElemenata=0; prvi=zadnji=0; }
    void izbaciElement();
    void ispisiElemente();
    Tip vratiVrijednost(int redniBroj);
    virtual void ubaciElement(const Tip &element);
};
template <typename Tip>
void red<Tip>::izbaciElement()
{
    if (brojElemenata)
    {
        cvor<Tip> *pom=prvi;

        prvi=prvi->vratiSljedeci();
        prvi->postaviPrethodni(0);
        brojElemenata--;

        delete pom;
    }
}
template <typename Tip>
void red<Tip>::ispisiElemente()
{
    cvor<Tip> *it;

    if (brojElemenata)
    {
        for (it=prvi; it!=zadnji; it=it->vratiSljedeci())
            cout << it->vratiVrijednost() << " ";
        cout << it->vratiVrijednost();
    }
}
template <typename Tip>
Tip red<Tip>::vratiVrijednost(int redniBroj)
{
    int i;
    cvor<Tip> *it;
    for (i=0, it=prvi; i<redniBroj; i++, it=it->vratiSljedeci());

    return it->vratiVrijednost();
}
template <typename Tip>
void red<Tip>::ubaciElement(const Tip &element)
{
    if (!brojElemenata)
    {
        cvor<Tip> *pom=new cvor<Tip> (element,0,0);
        prvi=zadnji=pom;
    }
    else
    {
        zadnji->postaviSljedeci(new cvor<Tip> (element, zadnji, 0));
        zadnji=zadnji->vratiSljedeci();
    }
    brojElemenata++;
}
template <typename Tip>
class sortiraniRed : public red<Tip>
{
    bool (*funkcija)(const Tip&, const Tip&);

    public:
    sortiraniRed (bool (*f)(const Tip&, const Tip&)) { funkcija=f; }
    void ubaciElement(const Tip &element);
};
template <typename Tip>
void sortiraniRed<Tip>::ubaciElement (const Tip &element)
{
    cvor<Tip> *pom;
    if (!red<Tip>::brojElemenata)
    {
        pom=new cvor<Tip> (element,0,0);
        red<Tip>::prvi=red<Tip>::zadnji=pom;
    }
    else
    {
        pom=red<Tip>::prvi;
        int i=1;
        while(pom && funkcija(pom->vratiVrijednost(),element) && i < red<Tip>::brojElemenata)
        {
            i++;
            pom=pom->vratiSljedeci();
        }
        if (pom==red<Tip>::prvi && funkcija(element,pom->vratiVrijednost()))
        {
            red<Tip>::prvi->postaviPrethodni(new cvor<Tip> (element,0,red<Tip>::prvi));
            red<Tip>::prvi=red<Tip>::prvi->vratiPrethodni();
        }
        else if (pom==0 || (pom==red<Tip>::zadnji && !funkcija(element,pom->vratiVrijednost())))
        {
            this->red<Tip>::ubaciElement(element);
        }
        else
        {
            cvor<Tip> *tmp=new cvor<Tip> (element,pom->vratiPrethodni(),pom);
            pom->vratiPrethodni()->postaviSljedeci(tmp);
            pom->postaviPrethodni(tmp);
        }
    }
    red<Tip>::brojElemenata++;
}
int main()
{
    sortiraniRed<int> a(porediDvaCijelaBroja);
    int n,i,tmp;

    cout << "Koliko zelite unijeti cijelih brojeva? "; cin >> n;
    cout << "Unesite cijele brojeve: ";

    for (i=0; i<n; i++)
    {
        cin >> tmp;
        a.ubaciElement(tmp);
    }

    cout << "Sadrzaj sortiranog reda: " << endl;
    a.ispisiElemente();

    a.izbaciElement();
    a.izbaciElement();

    cout << endl << "Sadrzaj reda nakon dva izbacena elementa: " << endl;
    a.ispisiElemente();

    return 0;
}
