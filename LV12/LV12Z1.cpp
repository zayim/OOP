#include <iostream>
using namespace std;
int mjeseci[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char imenaDana[][15] = {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja" };
char imenaMjeseci[][15] = { "Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar" };
class Datum
{
    int dan,mjesec,godina;

    public:
    enum Mjeseci {Januar, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar};
    enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    Datum(int dan, Mjeseci mjesec, int godina);
    void Postavi(int dan, Mjeseci mjesec, int godina);
    int Dan() const { return dan; }
    Mjeseci Mjesec() const { return Mjeseci(mjesec-1); }
    char *ImeMjeseca() const { return imenaMjeseci[mjesec-1]; }
    int Godina() const { return godina; }
    bool DaLiJePrestupna() const { return ((godina%4==0 && godina%100!=0) || (godina%400==0)); }
    int Sedmica() const { return (BrojDanaOdPocetkaGodine()/7 + 1); };
    int BrojDanaOdPocetkaGodine() const;
    Dani DanUSedmici() const;
    char *ImeDanaUSedmici() const { return imenaDana[int(DanUSedmici())]; }
    void Sljedeci();
    void Prethodni();
    void PomjeriZa(int brojDana);
    void IspisiKratko() const { cout << dan << ". " << mjesec << ". " << godina << "."; }
    void IspisiKompletno() const { cout << dan << "." << imenaMjeseci[mjesec-1] << " " << godina << ".(" << ImeDanaUSedmici() << ")"; }
};
Datum::Datum(int dan, Mjeseci mjesec, int godina)
{
    if (godina<=0) throw "Neispravan unos!";
    if (DaLiJePrestupna()) mjeseci[1]++;
    if (int(mjesec)<0 || int(mjesec)>11) throw "Neispravan unos!";
    if (dan<1 || dan>mjeseci[mjesec]) throw "Neispravan unos!";

    this->dan=dan; this->mjesec=int(mjesec)+1; this->godina=godina;

    mjeseci[1]=28;
}
void Datum::Postavi(int dan, Mjeseci mjesec, int godina)
{
    *this = Datum(dan,mjesec,godina);
}
int Datum::BrojDanaOdPocetkaGodine() const
{
    if (DaLiJePrestupna()) mjeseci[1]++;
    int protekloDana=dan-1;
    for (int i=0; i<mjesec-1; i++) protekloDana+=mjeseci[i];
    mjeseci[1]=28;
    return protekloDana;

}
Datum::Dani Datum::DanUSedmici() const
{
    int protekloDana=(godina-1)*365 + (godina-1)/4 - 3*(godina-1)/400; // uzimamo u obzir i prestupne godine...

    if (DaLiJePrestupna()) mjeseci[1]++;
    for (int i=0; i<mjesec-1; i++) protekloDana+=mjeseci[i];
    protekloDana+=dan-1;
    mjeseci[1]=28;

    return Dani(protekloDana%7);
}
void Datum::Sljedeci()
{
    if (DaLiJePrestupna()) mjeseci[1]++;
    dan++;
    if (dan>mjeseci[mjesec-1]) { dan-=mjeseci[mjesec-1]; mjesec++; }
    if (mjesec>12) { mjesec-=12; godina++; }

    mjeseci[1]=28;
}
void Datum::Prethodni()
{
    if (DaLiJePrestupna()) mjeseci[1]++;
    dan--;
    if (dan<1) { dan+=mjeseci[mjesec-2]; mjesec--; } if (dan==0) dan=31;
    if (mjesec<1) { mjesec+=12; godina--; }
    mjeseci[1]=28;
    if (godina<1) throw "Neispravan datum!";
}
void Datum::PomjeriZa(int brojDana)
{
    if (brojDana<0)
    {
        brojDana=-brojDana;
        while (dan < brojDana)
        {
            mjesec--;
            if (mjesec<1)
            {
                mjesec+=12; godina--;
                if (DaLiJePrestupna()) mjeseci[1]=29;
                else mjeseci[1]=28;
            }
            brojDana-=mjeseci[mjesec-1];
        }
        dan-=brojDana;
        mjeseci[1]=28;
    }
    else
    {
        while (dan + brojDana>mjeseci[mjesec-1])
        {
            brojDana-=mjeseci[mjesec-1]; mjesec++;
            if (mjesec>12)
            {
                mjesec-=12; godina++;
                if (DaLiJePrestupna()) mjeseci[1]=29;
                else mjeseci[1]=28;
            }
        }
        dan+=brojDana;
        mjeseci[1]=28;
    }
}
int main()
{
    try
    {
        Datum d(1,Datum::Juli,2012);

        cout << "Datum: "; d.IspisiKompletno(); cout << endl;
        d.Sljedeci();
        cout << "Sutra: "; d.IspisiKratko(); cout << endl;
        int pomak;
        cout << "Za koliko dana zelite pomjeriti datum? "; cin >> pomak;
        d.PomjeriZa(pomak);
        cout << "Pomjereno: "; d.IspisiKompletno(); cout << endl;
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
        cout << "Neki problemi... :S" << endl;
    }

    return 0;
}
