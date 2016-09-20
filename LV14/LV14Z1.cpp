#include <iostream>
#include <cmath>
#include <list>
using namespace std;
void ispisiKoeficijent(double koeficijent, int stepen, char promjenjiva, bool daLiJePrvi)
{
    if (koeficijent<0.) cout << "- ";
    else if(koeficijent>0. && !daLiJePrvi) cout << "+ ";
    if (koeficijent!=0.)
    {
        if (fabs(koeficijent)!=1.) cout << fabs(koeficijent) << " ";
        cout << promjenjiva;
        if (stepen!=1) cout << "^" << stepen;
        cout << " ";
    }
}
class Polinom
{
    protected:
    int stepen;
    char promjenjiva;
    double *koeficijenti;

    public:
    Polinom(int STEPEN, char IME) : stepen(STEPEN), promjenjiva(IME) { koeficijenti = new double[stepen+1]; }
    ~Polinom() { delete koeficijenti; }
    virtual void unesiKoeficijente();
    Polinom operator+(const Polinom &p);
    double operator() (double x);
    void ispisiPolinom();
    Polinom(const Polinom &p);
};
void Polinom::unesiKoeficijente()
{
    cout << "Unesi koeficijente polinoma " << stepen << ". stepena: ";
    for (int i=0; i<=stepen; i++) cin >> koeficijenti[i];
}
Polinom Polinom::operator+(const Polinom &p)
{
    if (promjenjiva!=p.promjenjiva) throw "Polinomi ne zavise od iste promjenjive!";
    int veciStepen,manjiStepen;
    const Polinom *veciPolinom;

    if (stepen > p.stepen)
    {
        veciStepen=stepen; manjiStepen=p.stepen;
        veciPolinom = this;
    }
    else
    {
        veciStepen=p.stepen; manjiStepen=stepen;
        veciPolinom=&p;
    }

    Polinom rezultat(veciStepen,promjenjiva);
    for (int i=0; i<=manjiStepen; i++) rezultat.koeficijenti[i]=koeficijenti[i] + p.koeficijenti[i];
    for (int i=manjiStepen+1; i<=veciStepen; i++) rezultat.koeficijenti[i]=veciPolinom->koeficijenti[i];

    return rezultat;
}
double Polinom::operator() (double x)
{
    double rezultat=0.,step=1.;
    for (int i=0; i<=stepen; i++)
    {
        rezultat+=step*koeficijenti[i];
        step*=x;
    }
    return rezultat;
}
void Polinom::ispisiPolinom()
{
    bool prvi=true;
    if (koeficijenti[0] < 0.) cout << "- ";
    if (koeficijenti[0]!=0.) { cout << fabs(koeficijenti[0]) << " "; prvi=false; }
    for (int i=1; i<stepen; i++)
    {
        ispisiKoeficijent(koeficijenti[i],i,promjenjiva,prvi);
        if (koeficijenti[i]!=0.) prvi=false;
    }
    ispisiKoeficijent(koeficijenti[stepen],stepen,promjenjiva,prvi);
}
Polinom::Polinom(const Polinom &p)
{
    stepen=p.stepen;
    promjenjiva=p.promjenjiva;
    koeficijenti=new double[stepen+1];
    for (int i=0; i<=stepen; i++) koeficijenti[i]=p.koeficijenti[i];
}
class CjelobrojniPolinom : public Polinom
{
    list<int> nule;

    public:
    CjelobrojniPolinom(int STEPEN, char IME) : Polinom(STEPEN,IME) {}
    void unesiKoeficijente();
    void nadjiCjelobrojneNule();
    void ispisiCjelobrojneNule();
    CjelobrojniPolinom(const Polinom &p) : Polinom(p) {}
};
void CjelobrojniPolinom::unesiKoeficijente()
{
    cout << "Unesi koeficijente cjelobrojnog polinoma " << stepen << ". stepena: ";
    for (int i=0; i<=stepen; i++)
    {
        cin >> koeficijenti[i];
        if (koeficijenti[i]!=int(koeficijenti[i])) throw "Koeficijent nije cjelobrojan!";
    }
}
void CjelobrojniPolinom::nadjiCjelobrojneNule()
{
    list<int>::iterator it;
    for (int i=1; i<=abs(koeficijenti[0]); i++)
    {
        int poz=i, neg=-i;

        if ((*this)(poz)==0.)
        {
            it=nule.begin();
            while (*it < poz && it!=nule.end() ) it++;
            nule.insert(it,poz);
        }

        if ((*this)(neg)==0.)
        {
            it=nule.begin();
            while (*it<neg && it!=nule.end() ) it++;
            nule.insert(it,neg);
        }
    }
}
void CjelobrojniPolinom::ispisiCjelobrojneNule()
{
    if (nule.empty()) { cout << "Nema cjelobrojnih nula!"; return; }
    cout << "Cjelobrojne nule su: ";
    list<int>::iterator i;
    for (i=nule.begin(); i!=nule.end(); i++) cout << *i << " ";
}

int main()
{
    try
    {
        CjelobrojniPolinom *P,*Q;
        int stepen;
        char promjenjiva;

        cout << "P -> Stepen i ime promjenjive: "; cin >> stepen >> promjenjiva;
        P = new CjelobrojniPolinom(stepen,promjenjiva);

        cout << "Q -> Stepen i ime promjenjive: "; cin >> stepen >> promjenjiva;
        Q = new CjelobrojniPolinom(stepen,promjenjiva);

        P->unesiKoeficijente(); Q->unesiKoeficijente();
        CjelobrojniPolinom *R = new CjelobrojniPolinom(*P + *Q);

        cout << "R=P+Q: ";
        R->ispisiPolinom();
        cout << endl;
        R->nadjiCjelobrojneNule();
        R->ispisiCjelobrojneNule();

        delete P; delete Q; delete R;
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
        cout << "Problemi..." << endl;
    }

    return 0;
}
