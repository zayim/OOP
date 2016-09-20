#include <iostream>
using namespace std;
class Sat
{
    int sekunde;

    public:
    Sat() { sekunde=0; }
    Sat(int s) { sekunde=s; }
    Sat(int h, int m, int s);
    void Postavi(int h, int m, int s);
    void Sljedeci() { sekunde++; }
    void Prethodni() { sekunde--; }
    void PomjeriZa(int pomak) { sekunde+=pomak; }
    int DajSate() const { return ((sekunde/3600)%24); }
    int DajMinute() const { return ((sekunde/60)%60); }
    int DajSekunde() const { return (sekunde%60); }
    void Ispisi() const;
};
Sat::Sat(int h, int m, int s)
{
    if (h<0 || h>23 || m<0 || m>59 || s<0 || s>59) throw "Neispravan unos!";
    sekunde=3600*h + 60*m + s;
}
void Sat::Postavi(int h, int m, int s)
{
    if (h<0 || h>23 || m<0 || m>59 || s<0 || s>59) throw "Neispravan unos!";
    sekunde=3600*h + 60*m + s;
}
void Sat::Ispisi() const
{
    if (DajSate()<10) cout << 0; cout << DajSate() << ":";
    if (DajMinute()<10) cout << 0; cout << DajMinute() << ":";
    if (DajSekunde()<10) cout << 0; cout << DajSekunde();
}
int main()
{
    try
    {
        Sat sat;
        int h,m,s,pomak,sec;

        cout << "Unesite vrijeme (H M S): "; cin >> h >> m >> s;
        sat.Postavi(h,m,s);

        cout << "Pomjeri vrijeme za koliko sekundi? "; cin >> pomak;
        sat.PomjeriZa(pomak);

        cout << "Vrijeme: "; sat.Ispisi(); cout << endl;

        cout << "Unesite broj sekundi: "; cin >> sec;
        cout << "Vrijeme: "; Sat(sec).Ispisi();
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(...)
    {
        cout << "Negdje ima problema..." << endl;
    }

    return 0;
}

