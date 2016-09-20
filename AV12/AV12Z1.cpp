#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
void ispisiKoeficijent(double koeficijent, int stepen, char promjenjiva, bool daLiJePrvi, ostream &izlaz)
{
    if (koeficijent<0.) izlaz << "- ";
    else if(koeficijent>0. && !daLiJePrvi) izlaz << "+ ";
    if (koeficijent!=0.)
    {
        if (fabs(koeficijent)!=1.) izlaz << fabs(koeficijent) << " ";
        izlaz << promjenjiva;
        if (stepen!=1) izlaz << "^" << stepen;
        izlaz << " ";
    }
}
class Polinom
{
    int stepen;
    char promjenjiva;
    double *koeficijenti;

    public:
    Polinom(int STEPEN, char IME) : stepen(STEPEN), promjenjiva(IME) { koeficijenti = new double[stepen+1]; }
    ~Polinom() { delete[] koeficijenti; }
    Polinom(const Polinom &p);
    Polinom& operator=(const Polinom &p);
    double operator[](int redniBroj);
    Polinom operator+(const Polinom &p);
    Polinom operator-(const Polinom &p);
    Polinom operator*(const Polinom &p);
    Polinom operator/(const Polinom &p);
    Polinom operator%(const Polinom &p) { return ((*this) - ((*this) / p)*p); }
    Polinom& operator+=(const Polinom &p) { return *this = *this + p; }
    Polinom& operator-=(const Polinom &p) { return *this = *this - p; }
    Polinom& operator*=(const Polinom &p) { return *this = *this * p; }
    Polinom& operator/=(const Polinom &p) { return *this = *this / p; }
    Polinom& operator%=(const Polinom &p) { return *this = *this % p; }
    bool operator==(const Polinom &p);
    bool operator!=(const Polinom &p) { return !(*this==p); }
    double operator() (double x);
    friend ostream& operator<<(ostream& izlaz, const Polinom &p);
    void unesiKoeficijente();
};
Polinom::Polinom(const Polinom &p)
{
    stepen=p.stepen;
    promjenjiva=p.promjenjiva;
    koeficijenti=new double[stepen+1];
    for (int i=0; i<=stepen; i++) koeficijenti[i]=p.koeficijenti[i];
}
Polinom& Polinom::operator=(const Polinom &p)
{
    stepen=p.stepen;
    promjenjiva=p.promjenjiva;
    delete[] koeficijenti;
    koeficijenti=new double[stepen+1];
    for (int i=0; i<=stepen; i++) koeficijenti[i]=p.koeficijenti[i];
    return *this;
}
double Polinom::operator[](int redniBroj)
{
    if (redniBroj<0 || redniBroj>stepen) throw "Pogresan indeks!";
    return koeficijenti[redniBroj];
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

    while (rezultat.koeficijenti[rezultat.stepen]==0.) rezultat.stepen--;

    return rezultat;
}
Polinom Polinom::operator-(const Polinom &p)
{
    if (promjenjiva!=p.promjenjiva) throw "Polinomi ne zavise od iste promjenjive!";
    int veciStepen,manjiStepen;
    bool daLiJePrviVeci=false;

    if (stepen > p.stepen)
    {
        veciStepen=stepen; manjiStepen=p.stepen;
        daLiJePrviVeci=true;
    }
    else
    {
        veciStepen=p.stepen; manjiStepen=stepen;
        daLiJePrviVeci=false;
    }

    Polinom rezultat(veciStepen,promjenjiva);
    for (int i=0; i<=manjiStepen; i++) rezultat.koeficijenti[i]=koeficijenti[i] - p.koeficijenti[i];
    for (int i=manjiStepen+1; i<=veciStepen; i++)
    {
        if (daLiJePrviVeci) rezultat.koeficijenti[i]=koeficijenti[i];
        else rezultat.koeficijenti[i]=-p.koeficijenti[i];
    }

    while (rezultat.koeficijenti[rezultat.stepen]==0.) rezultat.stepen--;

    return rezultat;
}
Polinom Polinom::operator*(const Polinom &p)
{
    if (promjenjiva!=p.promjenjiva) throw "Polinomi ne zavise od iste promjenjive!";

    Polinom rezultat(stepen+p.stepen,promjenjiva);
    for (int i=0; i<=stepen+p.stepen; i++) rezultat.koeficijenti[i]=0;

    for (int i=0; i<=stepen; i++)
    for (int j=0; j<=p.stepen; j++)
        rezultat.koeficijenti[i+j]+=koeficijenti[i]*p.koeficijenti[j];

    return rezultat;
}
Polinom Polinom::operator/(const Polinom &p)
{
    if (promjenjiva!=p.promjenjiva) throw "Polinomi ne zavise od iste promjenjive!";
    if (stepen<p.stepen) return Polinom(0,promjenjiva);

    Polinom rezultat(stepen-p.stepen,promjenjiva);
    for (int i=0; i<rezultat.stepen; i++) rezultat.koeficijenti[i]=0.;
    Polinom pomocni1=*this, pomocni2=p;
    int i=p.stepen;

    while (pomocni1.stepen >= p.stepen)
    {
        rezultat.koeficijenti[pomocni1.stepen-i]=pomocni1.koeficijenti[pomocni1.stepen]/p.koeficijenti[i];
        pomocni2 = Polinom(pomocni1.stepen-i,promjenjiva); for (int j=0; j<pomocni1.stepen-i; j++) pomocni2.koeficijenti[j]=0.;
        pomocni2.koeficijenti[pomocni1.stepen-i]=rezultat.koeficijenti[pomocni1.stepen-i];
        pomocni1=pomocni1 - pomocni2*p;
    }

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
ostream& operator<<(ostream& izlaz, const Polinom &p)
{
    bool prvi=true;
    if (p.koeficijenti[0] < 0.) izlaz << "- ";
    if (p.koeficijenti[0]!=0.) { izlaz << fabs(p.koeficijenti[0]) << " "; prvi=false; }
    for (int i=1; i<p.stepen; i++)
    {
        ispisiKoeficijent(p.koeficijenti[i],i,p.promjenjiva,prvi,izlaz);
        if (p.koeficijenti[i]!=0.) prvi=false;
    }
    ispisiKoeficijent(p.koeficijenti[p.stepen],p.stepen,p.promjenjiva,prvi,izlaz);

    return izlaz;
}
bool Polinom::operator==(const Polinom &p)
{
    if (stepen!=p.stepen || promjenjiva!=p.promjenjiva) return false;
    for  (int i=0; i<=stepen; i++) if (koeficijenti[i]!=p.koeficijenti[i]) return false;
    return true;
}
void Polinom::unesiKoeficijente()
{
    cout << "Unesi koeficijente polinoma " << stepen << ". stepena: ";
    for (int i=0; i<=stepen; i++) cin >> koeficijenti[i];
}
int main()
{
    try
    {
        Polinom *P,*Q;
        int stepen;
        char promjenjiva;

        cout << "Polinom P -> Unesi stepen i promjenjivu: "; cin >> stepen >> promjenjiva;
        P = new Polinom(stepen,promjenjiva); P->unesiKoeficijente();

        cout << "Polinom Q -> Unesi stepen i promjenjivu: "; cin >> stepen >> promjenjiva;
        Q = new Polinom(stepen,promjenjiva); Q->unesiKoeficijente();

        cout << "P: " << *P << endl << "Q: " << *Q << endl;

        Polinom R = *P + *Q;
        cout << "P+Q:  " << R << endl;
        R = *P - *Q;
        cout << "P-Q:  " << R << endl;
        R = *P * *Q;
        cout << "P*Q:  " << R << endl;
        R = *P / *Q;
        cout << "P/Q:  " << R << endl;
        R = *P % *Q;
        cout << "P%Q:  " << R << endl;

        *P += *Q;
        cout << "P=P+Q:  " << *P << endl;

        if (*P == *Q) cout << "P i Q su jednaki!" << endl;
        else cout << "P i Q nisu jednaki!" << endl;

        delete P; delete Q;
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
        cout << "Negdje ima problem :(" << endl;
    }
    return 0;
}
