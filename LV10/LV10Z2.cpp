#include <iostream>
using namespace std;
enum Pravci {Sjever, Istok, Jug, Zapad};
const char imenaPravaca[][10]={ "Sjever", "Istok", "Jug", "Zapad" };
class Robot
{
    int x,y;
    Pravci pravac;

    public:
    Robot(int X, int Y, Pravci p) { x=X; y=Y; pravac=p; }
    void PomjeriSe(int korak);
    void Nalijevo() { pravac=Pravci((int(pravac) + 3)%4); }
    void Nadesno() { pravac=Pravci((int(pravac) + 1)%4); }
    int Pozicija_x() const { return x; }
    int Pozicija_y() const { return y; }
    Pravci Orjentacija() const { return pravac; }
    void Ispisi() const { cout << "Robot se nalazi na poziciji (" << x << "," << y << ") i gleda na " << imenaPravaca[int(pravac)] << "." << endl; }
};
void Robot::PomjeriSe(int korak)
{
    switch (pravac)
    {
        case Sjever:
            y+=korak;
            break;
        case Istok:
            x+=korak;
            break;
        case Jug:
            y-=korak;
            break;
        case Zapad:
            x-=korak;
            break;
    }
}
int main()
{
    int x,y,pravac,komanda,korak;
    bool kraj=false;

    cout << "Pocetna pozicija (x y): "; cin >> x >> y;
    cout << "Pocetni pravac (Sjever = 1, Istok = 2, Jug = 3, Zapad = 4): "; cin >> pravac;
    Robot robot(x,y,Pravci(pravac));
    robot.Ispisi();

    while(!kraj)
    {
        cout << "UNESI KOMANDU\n1 = Rotiraj ulijevo\n2 = Rotiraj udesno\n3 = Pomjeri robota\n4 = kraj" << endl;
        cin >> komanda;
        if (komanda==1) robot.Nalijevo();
        else if (komanda==2) robot.Nadesno();
        else if (komanda==3)
        {
            cout << "Za koliko koraka cete pomjeriti robota? "; cin >> korak;
            robot.PomjeriSe(korak);
        }
        else if (komanda==4) kraj=true;

        if (!kraj) robot.Ispisi();
    }

    cout << "Kraj programa!" << endl;

    return 0;
}
