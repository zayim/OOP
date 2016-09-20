#include <iostream>
using namespace std;
class Sat
{
    int sati,minute,sekunde;

    public:
    Sat() { sati=minute=sekunde=0; }
    Sat(int h, int m, int s);
    void Postavi(int h, int m, int s);
    void Sljedeci();
    void Prethodni();
    void PomjeriZa(int pomak);
    int DajSate() const { return sati; }
    int DajMinute() const { return minute; }
    int DajSekunde() const { return sekunde; }
    void Ispisi() const;
};
Sat::Sat(int h, int m, int s)
{
    if (h<0 || h>23 || m<0 || m>59 || s<0 || s>59) throw "Neispravan unos!";
    sati=h; minute=m; sekunde=s;
}
void Sat::Postavi(int h, int m, int s)
{
    if (h<0 || h>23 || m<0 || m>59 || s<0 || s>59) throw "Neispravan unos!";
    sati=h; minute=m; sekunde=s;
}
void Sat::Sljedeci()
{
    sekunde++;
    if (sekunde>59) { sekunde-=60; minute++; }
    if (minute>59) { minute-=60; sati++; }
    if (sati>23) { sati-=24; }
}
void Sat::Prethodni()
{
    sekunde--;
    if (sekunde<0) { sekunde+=60; minute--; }
    if (minute<0) { minute+=60; sati--; }
    if (sati<0) { sati+=24; }
}
void Sat::PomjeriZa(int pomak)
{
    int t=3600*sati+60*minute+sekunde+pomak;
    sekunde=t%60; t/=60;
    minute=t%60; t/=60;
    sati=t%24;
}
void Sat::Ispisi() const
{
    if (sati<10) cout << 0; cout << sati << ":";
    if (minute<10) cout << 0; cout << minute << ":";
    if (sekunde<10) cout << 0; cout << sekunde;
}
int main()
{
    try
    {
        Sat sat;
        int h,m,s,pomak;

        cout << "Unesite vrijeme (H M S): "; cin >> h >> m >> s;
        sat.Postavi(h,m,s);

        cout << "Pomjeri vrijeme za koliko sekundi? "; cin >> pomak;
        sat.PomjeriZa(pomak);

        cout << "Vrijeme: "; sat.Ispisi(); cout << endl;
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
