#include <iostream>
using namespace std;
class Sat
{
    int h,m,s;

    public:
    Sat() { h=m=s=0; }
    void Postavi(int sati, int minute, int sekunde);
    void Sljedeci();
    void Ispisi() const;
};
void Sat::Postavi(int sati, int minute, int sekunde)
{
    if (sati<0 || sati>23 || minute<0 || minute>59 || sekunde<0 || sekunde>59) throw "Neispravan unos!";
    h=sati; m=minute; s=sekunde;
}
void Sat::Sljedeci()
{
    s++;
    if (s>59) { s-=60; m++; }
    if (m>59) { m-=60; h++; }
    if (h>23) { h-=24; }
}
void Sat::Ispisi() const
{
    if (h<10) cout << 0; cout << h << ":";
    if (m<10) cout << 0; cout << m << ":";
    if (s<10) cout << 0; cout << s;
}
int main()
{
    try
    {
        Sat sat;

        int h,m,s;
        cout << "Unesi neko vrijeme (format H M S): "; cin >> h >> m >> s;
        sat.Postavi(h,m,s);
        cout << "Postavljen sat: "; sat.Ispisi(); cout << endl;
        sat.Sljedeci();
        cout << "Povecano za 1s: "; sat.Ispisi();
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
