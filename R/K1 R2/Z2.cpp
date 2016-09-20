#include <iostream>
#include <cstring>
using namespace std;
template <typename Tip>
void Zamijeni(Tip* pocetak, Tip* kraj, bool (f)(Tip), Tip v)
{
    for (Tip* p=pocetak; p!=kraj; p++)
        if (f(*p)) *p=v;
}
bool a(char x) { return (x=='a'); }
int main()
{
    char recenica[100];

    cout << "Unesi recenicu: " << endl;
    cin.getline(recenica, sizeof recenica);
    Zamijeni(recenica,recenica+strlen(recenica),a,'b');
    cout << "Izmijenjena recenica: " << endl << recenica << endl;

    return 0;
}
