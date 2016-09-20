#include <iostream>
#include <string>
using namespace std;
string ntaRijec(string recenica, int n)
{
    if (n<1) throw "Drugi parametar manji od 1!";

    int i=0,rb=1,duzina=recenica.length();
    string rijec="";

    while (recenica[i]==' ') i++;

    while (i<duzina)
    {
        if (rb==n)
        {
            while (i<duzina && recenica[i]!=' ') rijec+=recenica[i++];
            return rijec;
        }

        rb++;
        while (i<duzina && recenica[i]!=' ') i++;
        while (i<duzina && recenica[i]==' ') i++;
    }

    throw "Drugi parametar je veci od broja rijeci!";
}
int main()
{
    string recenica;
    int n;

    cout << "Unesite recenicu: "; getline(cin,recenica);
    cout << "Unesite redni broj rijeci: "; cin >> n;

    try
    {
        cout << n << ". rijec: //" << ntaRijec(recenica,n) << "\\\\" << endl;
    }
    catch(const char poruka[])
    {
        cout << poruka << endl;
    }
    catch(...)
    {
        cout << "Nesto nije uredu :(" << endl;
    }

    return 0;
}
