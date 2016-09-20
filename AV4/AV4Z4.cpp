#include <iostream>
using namespace std;
template <typename Tip>
Tip* KreirajNiz(int n, Tip v)
{
    try
    {
        Tip *pocetak=new Tip[n];
        Tip *p,*kraj=pocetak+n;

        for (p=pocetak; p!=kraj; p++) *p=v;

        return pocetak;
    }
    catch(bad_alloc e)
    {
        throw "Kreiranje nije uspjelo";
    }
}
int main()
{
    try
    {
        int *niz1=KreirajNiz(10,3),*p1; // tip int
        for (p1=niz1; p1<niz1+10; p1++) cout << *p1 << " "; cout << endl;

        double *niz2=KreirajNiz(14,2.),*p2; // tip double
        for (p2=niz2; p2<niz2+14; p2++) cout << *p2 << " "; cout << endl;

        int *niz3=KreirajNiz<int>(27,'b'),*p3; // tip int
        for (p3=niz3; p3<niz3+27; p3++) cout << *p3 << " "; cout << endl;

        string *niz4=KreirajNiz<string>(44,"d"),*p4; // tip string
        for (p4=niz4; p4<niz4+44; p4++) cout << *p4 << " "; cout << endl;

        float *niz5=KreirajNiz<float>(15,5),*p5; // tip float
        for (p5=niz5; p5<niz5+15; p5++) cout << *p5 << " "; cout << endl;

        char *niz6=KreirajNiz(8,'a'),*p6; // tip char
        for (p6=niz6; p6<niz6+8; p6++) cout << *p6 << " "; cout << endl;

        const char* *niz7=KreirajNiz(12,"c"); // tip const char*
    }
    catch (const char poruka[])
    {
        cout << poruka;
    }

    return 0;
}
