#include <iostream>
using namespace std;
int mjeseci[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char imenaDana[][15] = {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja" };
const char imenaMjeseci[][15] = { "Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar" };
bool daLiJePrestupna(int godina) { return ((godina%4==0 && godina%100!=0) || (godina%400==0)); }
inline int abs(int n) { return (n<0 ? -n : n); }
class Datum
{
    int dan, mjesec, godina;

    public:
    Datum(int dan, int mjesec, int godina);
    int dajGodinu() { return godina; }
    int dajMjesec() { return mjesec; }
    int dajDan() { return dan; }
    const char* dajImeDanaUSedmici();
    Datum& operator++();
    Datum operator++(int);
    Datum& operator--();
    Datum operator--(int);
    Datum operator+(int broj);
    Datum operator-(int broj);
    int operator-(const Datum &d);
    bool operator==(const Datum &d) { return (dan==d.dan && godina==d.godina && mjesec==d.mjesec); }
    bool operator!=(const Datum &d) { return (dan!=d.dan || godina!=d.godina || mjesec!=d.mjesec); }
    bool operator<(const Datum &d);
    bool operator>(const Datum &d) { return !(*this == d || *this<d); }
    bool operator<=(const Datum &d) { return (*this == d || *this<d); }
    bool operator>=(const Datum &d) { return (*this == d || *this>d); }
    Datum operator+=(int broj) { return (*this = *this + broj); }
    Datum operator-=(int broj) { return (*this = *this - broj); }
    friend ostream& operator<<(ostream& izlaz, const Datum &d);
    friend istream& operator>>(istream& ulaz, Datum &d);
};
Datum::Datum(int dan, int mjesec, int godina)
{
    if (godina<=0) throw "Neispravan unos!";
    if (daLiJePrestupna(godina)) mjeseci[1]++;
    if (mjesec<1 || mjesec>12) throw "Neispravan unos!";
    if (dan<1 || dan>mjeseci[mjesec-1]) throw "Neispravan unos!";

    this->dan=dan; this->mjesec=mjesec; this->godina=godina;

    mjeseci[1]=28;
}
const char* Datum::dajImeDanaUSedmici()
{
    int protekloDana=(godina-1)*365 + (godina-1)/4 - 3*(godina-1)/400; // uzimamo u obzir i prestupne godine...

    if (daLiJePrestupna(godina)) mjeseci[1]++;
    for (int i=0; i<mjesec-1; i++) protekloDana+=mjeseci[i];
    protekloDana+=dan-1;
    mjeseci[1]=28;

    return imenaDana[protekloDana%7];
}
Datum& Datum::operator++()
{
    if (daLiJePrestupna(godina)) mjeseci[1]++;
    dan++;
    if (dan>mjeseci[mjesec-1]) { dan-=mjeseci[mjesec-1]; mjesec++; }
    if (mjesec>12) { mjesec-=12; godina++; }

    mjeseci[1]=28;
    return *this;
}
Datum Datum::operator++(int)
{
    Datum pomocni(dan,mjesec,godina);

    if (daLiJePrestupna(godina)) mjeseci[1]++;
    dan++;
    if (dan>mjeseci[mjesec-1]) { dan-=mjeseci[mjesec-1]; mjesec++; }
    if (mjesec>12) { mjesec-=12; godina++; }

    mjeseci[1]=28;
    return pomocni;
}
Datum& Datum::operator--()
{
    if (daLiJePrestupna(godina)) mjeseci[1]++;
    dan--;
    if (dan<1) { dan+=mjeseci[mjesec-2]; mjesec--; } if (dan==0) dan=31;
    if (mjesec<1) { mjesec+=12; godina--; }
    mjeseci[1]=28;
    if (godina<1) throw "Neispravan datum!";

    return *this;
}
Datum Datum::operator--(int)
{
    Datum pomocni(dan,mjesec,godina);

    if (daLiJePrestupna(godina)) mjeseci[1]++;
    dan--;
    if (dan<1) { dan+=mjeseci[mjesec-2]; mjesec--; } if (dan==0) dan=31;
    if (mjesec<1) { mjesec+=12; godina--; }
    mjeseci[1]=28;
    if (godina<1) throw "Neispravan datum!";

    return pomocni;
}
Datum Datum::operator+(int broj)
{
    if (broj<0) return *this - (-broj);
    Datum pomocni(dan,mjesec,godina);
    while (pomocni.dan + broj>mjeseci[pomocni.mjesec-1])
    {
        broj-=mjeseci[pomocni.mjesec-1];  pomocni.mjesec++;
        if (pomocni.mjesec>12)
        {
            pomocni.mjesec-=12; pomocni.godina++;
            if (daLiJePrestupna(pomocni.godina)) mjeseci[1]=29;
            else mjeseci[1]=28;
        }
    }
    pomocni.dan+=broj;
    mjeseci[1]=28;
    return pomocni;
}
Datum Datum::operator-(int broj)
{
    if (broj<0) return *this + (-broj);
    Datum pomocni(dan,mjesec,godina);
    while (pomocni.dan < broj)
    {
        pomocni.mjesec--;
        if (pomocni.mjesec<1)
        {
            pomocni.mjesec+=12; pomocni.godina--;
            if (daLiJePrestupna(pomocni.godina)) mjeseci[1]=29;
            else mjeseci[1]=28;
        }
        broj-=mjeseci[pomocni.mjesec-1];
    }
    pomocni.dan-=broj;
    mjeseci[1]=28;
    return pomocni;
}
int Datum::operator-(const Datum &d)
{
    int proteklo1=(godina-1)*365 + (godina-1)/4 - 3*(godina-1)/400;
    int proteklo2=(d.godina-1)*365 + (d.godina-1)/4 - 3*(d.godina-1)/400;

    if (daLiJePrestupna(godina)) mjeseci[1]++;
    for (int i=0; i<mjesec-1; i++) proteklo1+=mjeseci[i];
    mjeseci[1]=28;
    proteklo1+=dan-1;

    if (daLiJePrestupna(d.godina)) mjeseci[1]++;
    for (int i=0; i<d.mjesec-1; i++) proteklo2+=mjeseci[i];
    mjeseci[1]=28;
    proteklo2+=d.dan-1;

    return abs(proteklo1-proteklo2);
}
bool Datum::operator<(const Datum &d)
{
    if (godina<d.godina) return true;
    else if (godina==d.godina)
    {
        if (mjesec<d.mjesec) return true;
        else if (mjesec==d.mjesec)
        {
            if (dan<d.dan) return true;
            else return false;
        }
        return false;
    }
    return false;
}
ostream& operator<<(ostream& izlaz, const Datum &d)
{
    return (izlaz << d.dan << ". " << imenaMjeseci[d.mjesec-1] << " " << d.godina << ".");
}
istream& operator>>(istream& ulaz, Datum &d)
{
    char kroz;
    int D,M,G;

    cin >> D >> kroz >> M >> kroz >> G;
    try
    {
        d=Datum(D,M,G);
    }
    catch(...)
    {
        ulaz.setstate(ios::failbit);
    }
    return ulaz;
}
int main()
{
    try
    {
        Datum d1(6,2,1992),d2(28,6,2012);

        cout << "Najvazniji datum na svijetu: " << d1 << endl;
        cout << "Zadatak radjen datuma: " << d2 << endl;

        cout << "Unesite danasnji datum (D/M/G): "; cin >> d1;
        if (cin) cout << "Datum: " << d1 << endl << "Dan u sedmici: " << d1.dajImeDanaUSedmici() << endl;
        else { cout << "Pogresan unos!"; cin.ignore(); cin.clear(); }

        cout << "Unesite jos jedan datum: "; cin >> d2;
        cout << "Datum D1: " << d1 << endl << "Datum D2: " << d2 << endl;
        cout << "D1==D2: " << (d1==d2) << endl;
        cout << "D1!=D2: " << (d1!=d2) << endl;
        cout << "D1<D2: " << (d1<d2) << endl;
        cout << "D1>D2: " << (d1>d2) << endl;
        cout << "D1<=D2: " << (d1<=d2) << endl;
        cout << "D1>=D2: " << (d1>=d2) << endl;
        cout << "D1 - D2: " << (d1-d2) << endl;

        int pomak;
        cout << "Unesite pomak (u danima): "; cin >> pomak;
        cout << "Pomaknut datum D1: " << (d1+pomak) << endl;

        cout << "Sutrasnji dan u odnosu na D2: " << ++d2 << endl;

    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(bad_alloc e)
    {
        cout << "Problemi s memorijom!" << endl;
    }
    catch(...)
    {
        cout << "Negdje je doslo do greske!" << endl;
    }

    return 0;
}
