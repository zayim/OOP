#include <iostream>
#include <cmath>
using namespace std;
double f(double x, double n)
{
    if (n<0 || n!=int(n)) throw "n nije prirodan broj ili nula!";

    int predznak=1;
    double suma=0,korijen=0,stepen=1;

    for (int i=0; i<=n; i++)
    {
        korijen=x*(x+i)-predznak*i*i;
        if (korijen<0) throw korijen;
        if (korijen==0) throw i;

        suma+=stepen/sqrt(korijen);
        stepen*=x; predznak*=-1;
    }

    return suma;
}
int main()
{
    double x,n,rez;

    while (true)
    {
        cout << "Unesite x i n: "; cin >> x >> n;
        try
        {
            rez=f(x,n);
            cout << "f(x,n): " << rez << endl;
        }
        catch(const char poruka[])
        {
            cout << poruka << endl;
        }
        catch(double x)
        {
            cout << "Ne mozemo izracunati korijen iz " << x << "!" << endl;
        }
        catch(int i)
        {
            cout << "Doslo je do nule u nazivniku u " << i << ". iteraciji!" << endl;
        }
        catch(...)
        {
            cout << "Nesto nije uredu :(" << endl;
        }
        cout << endl;
    }
}
