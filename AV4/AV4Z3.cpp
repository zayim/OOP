#include <iostream>
using namespace std;
template <typename Tip>
bool JednakiBlokovi(Tip *pocetak1, Tip *kraj1, Tip *pocetak2)
{
    Tip *p;

    for (p=pocetak1; p<kraj1; p++) if (*p != *(pocetak2 + (p-pocetak1)) ) return false;
    return true;
}
char* NadjiPodstring(char *str1, char *str2)
{
    char *p=str1,*kraj;
    int duzina_str1=0,duzina_str2=0;

    while (*(str1 + ++duzina_str1));
    while (*(str2 + ++duzina_str2));

    if (duzina_str1 < duzina_str2) return NULL;

    kraj = str1 + (duzina_str1 - duzina_str2) + 1;

    for (p=str1; p!=kraj; p++)
        if (JednakiBlokovi(p,p+duzina_str2,str2)) return p;

    return NULL;
}
int main()
{
    char string1[100],string2[100],*pok;

    cout << "Unesite 2 stringa: "; cin >> string1 >> string2;

    pok=NadjiPodstring(string1,string2);

    if (!pok) cout << "'" << string2 << "' se ne sadrzi u '" << string1 << "' !!!" << endl;
    else cout << "'" << string2 << "' se sadrzi u '" << string1 << "' na poziciji: " << (pok-string1) << endl;

    return 0;
}
