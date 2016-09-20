#include <iostream>
using namespace std;
struct Vrijeme
{
    int sati,minute,sekunde;
};
void Postavi(Vrijeme &v,int h, int m, int s)
{
    v.sati=h; v.minute=m; v.sekunde=s;
}
void IspisiVrijeme(const Vrijeme &v)
{
    if (v.sati<10) cout << 0; cout << v.sati << ":";
    if (v.minute<10) cout << 0; cout << v.minute << ":";
    if (v.sekunde<10) cout << 0; cout << v.sekunde;
}
Vrijeme Saberi(const Vrijeme &v1, const Vrijeme &v2)
{
    Vrijeme rezultat;
    int sec1=3600*v1.sati+60*v1.minute+v1.sekunde;
    int sec2=3600*v2.sati+60*v2.minute+v2.sekunde;
    int sec=(sec1+sec2)%(24*3600);
    rezultat.sekunde=sec%60; sec/=60;
    rezultat.minute=sec%60; sec/=60;
    rezultat.sati=sec;
    return rezultat;
}
int main()
{
    Vrijeme v1,v2;
    int h,m,s;

    cout << "Unesi prvo vrijeme (H M S): "; cin >> h >> m >> s;
    Postavi(v1,h,m,s);
    cout << "Unesi drugo vrijeme: "; cin >> h >> m >> s;
    Postavi(v2,h,m,s);

    cout << "V1:    "; IspisiVrijeme(v1); cout << endl;
    cout << "V2:    "; IspisiVrijeme(v2); cout << endl;
    cout << "V1+V2: "; IspisiVrijeme(Saberi(v1,v2)); cout << endl;

    return 0;
}
