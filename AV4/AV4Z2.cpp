#include <iostream>
using namespace std;
bool DaLiJeSlovo(char x)
{
    return (x>='A' && x<='Z') || (x>='a' && x<='z');
}
char MaloSlovo(char x)
{
    if (x<'a') return char(x + 'a'-'A');
    else return x;
}
bool DaLiJePalindrom(char* x)
{
    char *kraj=x,*pocetak=x;
    while (*(++kraj));

    while (pocetak < kraj)
    {
        while (!DaLiJeSlovo(*pocetak) && pocetak<kraj) pocetak++;
        while (!DaLiJeSlovo(*kraj) && pocetak<kraj) kraj--;
        if (MaloSlovo(*pocetak) != MaloSlovo(*kraj)) return false;
        pocetak++; kraj--;
    }

    return true;
}
int main()
{
    char recenica[100];
    cin.getline(recenica, sizeof recenica);

    cout << (DaLiJePalindrom(recenica) ? "Jeste " : "Nije ") << "palindrom" << endl;

    return 0;
}
