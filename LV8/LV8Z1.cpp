#include <iostream>
#include <cmath>
using namespace std;
struct VektorN
{
    int dimenzija;
    double *koordinate;
};
VektorN KreirajVektorN(int dimenzija)
{
    VektorN rezultat;
    rezultat.dimenzija=dimenzija;
    try
    {
        rezultat.koordinate=new double[dimenzija];
        for (int i=0; i<dimenzija; i++) rezultat.koordinate[i]=0.;
    }
    catch(bad_alloc)
    {
        throw "Problemi s memorijom!";
    }
    return rezultat;
}
VektorN Zbir(VektorN v1, VektorN v2)
{
    if (v1.dimenzija != v2.dimenzija) throw "Vektori nisu istih dimenzija!";
    VektorN rezultat = KreirajVektorN(v1.dimenzija);
    for (int i=0; i<rezultat.dimenzija; i++)
        rezultat.koordinate[i]=v1.koordinate[i] + v2.koordinate[i];

    return rezultat;
}
VektorN Razlika(VektorN v1, VektorN v2)
{
    if (v1.dimenzija != v2.dimenzija) throw "Vektori nisu istih dimenzija!";
    VektorN rezultat = KreirajVektorN(v1.dimenzija);
    for (int i=0; i<rezultat.dimenzija; i++)
        rezultat.koordinate[i]=v1.koordinate[i] - v2.koordinate[i];

    return rezultat;
}
double SkalarniProizvod(VektorN v1, VektorN v2)
{
    if (v1.dimenzija != v2.dimenzija) throw "Vektori nisu istih dimenzija!";
    double proizvod=0.;
    for (int i=0; i<v1.dimenzija; i++) proizvod+=v1.koordinate[i]*v2.koordinate[i];
    return proizvod;
}
double Norma(VektorN v1)
{
    double norma=0.;
    for (int i=0; i<v1.dimenzija; i++) norma+=v1.koordinate[i]*v1.koordinate[i];
    return sqrt(norma);
}
void Ispisi(VektorN v1)
{
    if (v1.dimenzija)
    {
        cout << "{ ";
        for (int i=0; i<v1.dimenzija-1; i++) cout << v1.koordinate[i] << ", ";
        cout << v1.koordinate[v1.dimenzija-1] << " }";
    }
    else cout << "{ }";
}
int main()
{
    try
    {
        VektorN v1, v2, rezultat1;
        int dim1, dim2;
        double rezultat2;

        cout << "Unesite dimenziju prvog vektora:   "; cin >> dim1;
        v1=KreirajVektorN(dim1);
        cout << "Unesite koordinate prvog vektora:  ";
        for (int i=0; i<dim1; i++) cin >> v1.koordinate[i];

        cout << "Unesite dimenziju drugog vektora:  "; cin >> dim2;
        v2=KreirajVektorN(dim2);
        cout << "Unesite koordinate drugog vektora: ";
        for (int i=0; i<dim2; i++) cin >> v2.koordinate[i];

        rezultat1 = Zbir(v1,v2);
        cout << "Zbir vektora:      "; Ispisi(rezultat1); cout << endl;

        rezultat1 = Razlika(v1,v2);
        cout << "Razlika vektora:   "; Ispisi(rezultat1); cout << endl;

        rezultat2=SkalarniProizvod(v1,v2);
        cout << "Skalarni proizvod: " << rezultat2 << endl;

        rezultat2=Norma(v1);
        cout << "Norma vektora v1:  " << rezultat2 << endl;

        delete[] v1.koordinate; delete[] v2.koordinate;
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
