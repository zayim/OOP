#include <iostream>
using namespace std;
struct Matrica
{
    int brojKolona, brojVrsta;
    double **elementi;
};
void UnistiMatricu(Matrica &m)
{
    if (m.elementi!=NULL)
        for (int i=0; i<m.brojVrsta; i++) delete[] m.elementi[i];
    delete[] m.elementi;
}
Matrica KreirajMatricu(int vrste, int kolone)
{
    Matrica m;
    m.brojKolona=kolone;
    m.brojVrsta=vrste;
    m.elementi=NULL;
    try
    {
        m.elementi = new double* [m.brojVrsta];
        for (int i=0; i<m.brojVrsta; i++) m.elementi[i]=NULL;
        for (int i=0; i<m.brojVrsta; i++) m.elementi[i]=new double[m.brojKolona];
    }
    catch(bad_alloc)
    {
        UnistiMatricu(m);
        throw;
    }
    return m;
}
Matrica SaberiMatrice(const Matrica &m1, const Matrica &m2)
{
    if (m1.brojKolona!=m2.brojVrsta) throw "Matrice se ne mogu sabrati!";

    Matrica rezultat =  KreirajMatricu(m1.brojVrsta,m2.brojKolona);
    double zbir=0.;

    for (int i=0; i<rezultat.brojVrsta; i++)
        for (int j=0; j<rezultat.brojKolona; j++)
        {
            zbir=0.;
            for (int k=0; k<m1.brojKolona; k++) zbir+=m1.elementi[i][k]*m2.elementi[k][j];
            rezultat.elementi[i][j]=zbir;
        }
    return rezultat;
}
void UnesiMatricu(Matrica &m)
{
    cout << "Unesite matricu formata " << m.brojVrsta << "x" << m.brojKolona << ": " << endl;
    for (int i=0; i<m.brojVrsta; i++)
    for (int j=0; j<m.brojKolona; j++) cin >> m.elementi[i][j];
}
void IspisiMatricu(const Matrica &m)
{
    cout << "Ispis matrice: " << endl;
    for (int i=0; i<m.brojVrsta; i++)
    {
        for (int j=0; j<m.brojKolona; j++) cout << m.elementi[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    try
    {
        Matrica m1,m2,m3;
        int dim1,dim2;

        cout << "Unesite dimenzije prve matrice: "; cin >> dim1 >> dim2;
        m1=KreirajMatricu(dim1,dim2); UnesiMatricu(m1);

        cout << "Unesite dimenzije druge matrice: "; cin >> dim1 >> dim2;
        m2=KreirajMatricu(dim1,dim2); UnesiMatricu(m2);

        m3=SaberiMatrice(m1,m2);
        cout << "ZBIR -> "; IspisiMatricu(m3);

        UnistiMatricu(m1); UnistiMatricu(m2); UnistiMatricu(m3);
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(bad_alloc)
    {
        cout << "Problemi s memorijom..." << endl;
    }
    catch(...)
    {
        cout << "Negdje je doslo do problema..." << endl;
    }
    return 0;
}
