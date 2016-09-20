#include <iostream>
using namespace std;
struct Skup
{
    int velicina,maxVelicina;
    double *elementi;
};
Skup KreirajSkup(int maksimalna_velicina)
{
    Skup rezultat;
    rezultat.velicina=0;
    rezultat.maxVelicina=maksimalna_velicina;
    try
    {
        rezultat.elementi=new double[rezultat.maxVelicina];
    }
    catch(bad_alloc)
    {
        throw "Problemi s memorijom!";
    }
    return rezultat;
}
Skup Unija(Skup s1, Skup s2)
{
    bool ima=false;
    Skup rezultat=KreirajSkup(s1.maxVelicina+s2.maxVelicina);
    rezultat.velicina+=s1.velicina;
    for (int i=0; i<s1.velicina; i++) rezultat.elementi[i]=s1.elementi[i];
    for (int i=0; i<s2.velicina; i++)
    {
        ima=false;
        for (int j=0; j<s1.velicina; j++)
            if (s2.elementi[i]==s1.elementi[j]) { ima=true; break; }
        if (!ima) rezultat.elementi[rezultat.velicina++]=s2.elementi[i];
    }
    return rezultat;
}
Skup Razlika(Skup s1, Skup s2)
{
    bool ima=false;
    Skup rezultat=KreirajSkup(s1.maxVelicina);

    for (int i=0; i<s1.velicina; i++)
    {
        ima=false;
        for (int j=0; j<s2.velicina; j++)
            if (s1.elementi[i]==s2.elementi[j]) { ima=true; break; }

        if (!ima) rezultat.elementi[rezultat.velicina++]=s1.elementi[i];
    }

    return rezultat;
}
Skup Presjek(Skup s1, Skup s2)
{
    bool ima=false;
    Skup rezultat=KreirajSkup(s1.maxVelicina);

    for (int i=0; i<s1.velicina; i++)
    {
        ima=false;
        for (int j=0; j<s2.velicina; j++)
            if (s1.elementi[i]==s2.elementi[j]) { ima=true; break; }

        if (ima) rezultat.elementi[rezultat.velicina++]=s1.elementi[i];
    }

    return rezultat;
}
void Ispisi(Skup s)
{
    if (s.velicina)
    {
        cout << "{ ";
        for (int i=0; i<s.velicina-1; i++) cout << s.elementi[i] << ", ";
        cout << s.elementi[s.velicina-1] << " }";
    }
    else cout << "Prazan skup!";
}
void DodajElement(Skup &s, double element)
{
    bool ima=false;
    for (int i=0; i<s.velicina; i++)
        if (s.elementi[i]==element) { ima=true; break; }
    if (ima) return;

    if (s.velicina >= s.maxVelicina)
    {
        double *pomocni = new double[s.velicina];
        for (int i=0; i<s.velicina; i++) pomocni[i]=s.elementi[i];
        delete[] s.elementi;
        s.maxVelicina*=2;
        s.elementi=new double[s.maxVelicina];
        for (int i=0; i<s.velicina; i++) s.elementi[i]=pomocni[i];
        delete[] pomocni;
    }
    s.elementi[s.velicina++]=element;
}
int main()
{
    Skup s1,s2;
    int max;
    double tmp;

    cout << "Unesite max. broj elemenata prvog skupa: "; cin >> max;
    s1=KreirajSkup(max);
    cout << "Unesite max. broj elemenata drugog skupa: "; cin >> max;
    s2=KreirajSkup(max);

    cout << "Unosite elemente prvog skupa (unesite 0 za  kraj): ";
    while (tmp!=0.)
    {
        cin >> tmp;
        if (tmp!=0.) DodajElement(s1,tmp);
    }

    tmp=1.;
    cout << "Unosite elemente drugog skupa (unesite 0 za  kraj): ";
    while (tmp!=0.)
    {
        cin >> tmp;
        if (tmp!=0.) DodajElement(s2,tmp);
    }

    Skup rezultat;

    rezultat=Unija(s1,s2);
    cout << "Unija: "; Ispisi(rezultat); cout << endl;
    rezultat=Razlika(s1,s2);
    cout << "Razlika: "; Ispisi(rezultat); cout << endl;
    rezultat=Presjek(s1,s2);
    cout << "Presjek: "; Ispisi(rezultat); cout << endl;

    return 0;
}
