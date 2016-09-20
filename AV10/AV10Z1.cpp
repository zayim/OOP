#include <iostream>
#include <algorithm>
using namespace std;
inline int abs(int x) { return (x<0 ? -x : x); }
int nzd(int a,int b)
{
    if (b==0) return abs(a);
    if (a<b) return nzd(abs(a),abs(b)%abs(a));
    return nzd(abs(b),abs(a)%abs(b));
}
class Razlomak
{
    int brojnik,nazivnik;

    public:
    Razlomak(int a, int b);
    Razlomak(int a) { brojnik=a; nazivnik=1; }
    Razlomak() { brojnik=0; nazivnik=1; }
    int dajNazivnik() const { return nazivnik; }
    int dajBrojnik() const { return brojnik; }
    Razlomak operator+(const Razlomak &r) const { return Razlomak(r.nazivnik*brojnik + r.brojnik*nazivnik,nazivnik*r.nazivnik); }
    Razlomak operator-(const Razlomak &r) const { return Razlomak(r.nazivnik*brojnik - r.brojnik*nazivnik,nazivnik*r.nazivnik); }
    Razlomak operator*(const Razlomak &r) const { return Razlomak(r.dajBrojnik()*brojnik,r.dajNazivnik()*nazivnik); }
    Razlomak operator/(const Razlomak &r) const { return Razlomak(r.dajNazivnik()*brojnik,r.dajBrojnik()*nazivnik); }
    Razlomak operator+() const { return *this; }
    Razlomak operator-() { return Razlomak(-brojnik,nazivnik); }
    Razlomak operator+=(const Razlomak &r) { return (*this = *this + r); }
    Razlomak operator-=(const Razlomak &r) { return (*this = *this - r); }
    Razlomak operator*=(const Razlomak &r) { return (*this = *this * r); }
    Razlomak operator/=(const Razlomak &r) { return (*this = *this / r); }
    Razlomak operator++() { return (*this=*this+Razlomak(1,1)); }
    Razlomak operator++(int) { Razlomak pom=*this; *this=*this+Razlomak(1,1); return pom; }
    Razlomak operator--() { return (*this=*this-Razlomak(1,1)); }
    Razlomak operator--(int) { Razlomak pom=*this; *this=*this-Razlomak(1,1); return pom; }
    bool operator<(const Razlomak &r) const { return (brojnik*r.nazivnik<nazivnik*r.brojnik); }
    bool operator==(const Razlomak &r) const { return (brojnik==r.brojnik && nazivnik==r.nazivnik); }
    bool operator>(const Razlomak &r) const { return (brojnik*r.nazivnik>nazivnik*r.brojnik); }
    bool operator<=(const Razlomak &r) const { return (*this<r || *this==r); }
    bool operator>=(const Razlomak &r) const { return (*this>r || *this==r); }
    bool operator!=(const Razlomak &r) const { return !(*this==r); }
    operator double() { return double(brojnik)/double(nazivnik); }
    friend int nzd(int a, int b);
    friend ostream &operator<< (ostream &izlaz, const Razlomak &r);
    friend istream &operator>> (istream &ulaz, Razlomak &r);

};
Razlomak::Razlomak(int a, int b)
{
    if (!b) throw "Nazivnik ne moze biti nula!";
    int d=nzd(a,b);
    brojnik=a/d;
    nazivnik=b/d;
    if (nazivnik<0) { nazivnik=-nazivnik; brojnik=-brojnik; }
}
ostream &operator<< (ostream& izlaz, const Razlomak &r)
{
    izlaz << r.dajBrojnik();
    if (r.dajNazivnik()!=1) izlaz << "/" << r.dajNazivnik();
    return izlaz;
}
istream &operator>> (istream &ulaz, Razlomak &r)
{
    int brojnik,nazivnik;
    char kroz;

    ulaz >> brojnik;
    if (ulaz.peek()=='/')
    {
        ulaz >> kroz >> nazivnik;
        r = Razlomak(brojnik,nazivnik);
    }
    else r=Razlomak(brojnik);
    return ulaz;
}
int main()
{
    try
    {
        Razlomak r1,r2,r3;

        cout << "Unesi prvi razlomak:  "; cin >> r1;
        cout << "Unesi drugi razlomak: "; cin >> r2;

        r3=r1+r2;
        cout << "Zbir:     " << r3 << endl;
        r3=r1-r2;
        cout << "Razlika:  " << r3 << endl;
        r3=r1*r2;
        cout << "Proizvod: " << r3 << endl;
        r3=r1/r2;
        cout << "Kolicnik: " << r3 << endl;

        r1+=r2;
        cout << "r1+=r2: " << r1 << endl;

        cout << "r1 = " << r1 << "  r2 = " << r2 << endl;
        if (r1==r2) cout << "r1 i r2 su jednaki!" << endl;
        else cout << "r1 i r2 su razliciti!" << endl;
        if (r1<r2) cout << "r1 je manji" << endl;
        if (r1>r2) cout << "r2 je manji" << endl;

        Razlomak *niz;
        int n;
        cout << "Unesite broj elemenata niza: "; cin >> n;
        niz = new Razlomak[n];
        cout << "Unesite razlomke: ";
        for (int i=0; i<n; i++) cin >> niz[i];

        sort(niz,niz+n);

        cout << "Sortirani razlomci: ";
        for (int i=0; i<n; i++) cout << niz[i] << " ";
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(...)
    {
        cout << "Negdje je doslo do problema..." << endl;
    }

    return 0;
}
