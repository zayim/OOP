#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Student
{
    protected:
    int brojIndexa,brojOcjena;
    double prosjecnaOcjena;
    string ime,prezime;

    public:
    int vratiIndex() { return brojIndexa; }
    Student (int INDEX, string IME, string PREZIME);
    void upisiOcjenu(int ocjena);
    virtual void ispisiPodatke();
};
Student::Student (int INDEX, string IME, string PREZIME)
{
    brojIndexa=INDEX; ime=IME; prezime=PREZIME;
    prosjecnaOcjena=5.; brojOcjena=0;
}
void Student::upisiOcjenu(int ocjena)
{
    if (brojOcjena==0) prosjecnaOcjena=ocjena;
    else prosjecnaOcjena = (brojOcjena*prosjecnaOcjena + ocjena)/(brojOcjena+1);
    brojOcjena++;
}
void Student::ispisiPodatke()
{
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "Student " << ime << " " << prezime << " sa brojem indexa " << brojIndexa << " ima prosjek " << prosjecnaOcjena << endl;
}
class Student_VI_stepena : public Student
{
    public:
    Student_VI_stepena(int INDEX, string IME, string PREZIME) : Student(INDEX,IME,PREZIME) {}
    void ispisiPodatke();
};
void Student_VI_stepena::ispisiPodatke()
{
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "Student VI stepena " << ime << " " << prezime << " sa brojem indexa " << brojIndexa << " ima prosjek " << prosjecnaOcjena << "." << endl;
}
class Student_VII_stepena : public Student
{
    public:
    Student_VII_stepena(int INDEX, string IME, string PREZIME) : Student(INDEX,IME,PREZIME) {}
    void ispisiPodatke();
};
void Student_VII_stepena::ispisiPodatke()
{
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "Student VII stepena " << ime << " " << prezime << " sa brojem indexa " << brojIndexa << " ima prosjek " << prosjecnaOcjena << "." << endl;
}
class Student_postdiplomac : public Student
{
    int godinaDiplomiranja;

    public:
    Student_postdiplomac(int INDEX, string IME, string PREZIME, int GODINA) : Student(INDEX,IME,PREZIME), godinaDiplomiranja(GODINA) {}
    void ispisiPodatke();
};
void Student_postdiplomac::ispisiPodatke()
{
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "Student postdiplomskog studija " << ime << " " << prezime << " sa brojem indexa " << brojIndexa << ", diplomirao godine " <<
    godinaDiplomiranja << ", ima prosjek " << prosjecnaOcjena << "." << endl;
}
class StudentskaSluzba
{
    int brojStudenata;
    const int maxBrojStudenata;
    Student** studenti;

    public:
    StudentskaSluzba(int kapacitet);
    ~StudentskaSluzba();
    StudentskaSluzba(const StudentskaSluzba &sS);
    StudentskaSluzba operator=(const StudentskaSluzba &sS);
    void upisiStudenta(int INDEX, string IME, string PREZIME, int GODINA);
    void upisiOcjenu(int index, int ocjena);
    void ispisiSpisak();
};
StudentskaSluzba::StudentskaSluzba(int kapacitet) : maxBrojStudenata(kapacitet), brojStudenata(0)
{
    studenti = new Student*[maxBrojStudenata];
    for (int i=0; i<maxBrojStudenata; i++) studenti[i]=NULL;
}
StudentskaSluzba::~StudentskaSluzba()
{
    if (studenti) for (int i=0; i<brojStudenata; i++) delete studenti[i];
    delete[] studenti;
}
void StudentskaSluzba::upisiStudenta(int INDEX, string IME, string PREZIME, int GODINA)
{
    if (brojStudenata>=maxBrojStudenata) throw "Nema vise mjesta!";
    if (GODINA==6) studenti[brojStudenata]= new Student_VI_stepena(INDEX,IME,PREZIME);
    else if (GODINA==7) studenti[brojStudenata]= new Student_VII_stepena(INDEX,IME,PREZIME);
    else studenti[brojStudenata]= new Student_postdiplomac(INDEX,IME,PREZIME,GODINA);
    brojStudenata++;
}
void StudentskaSluzba::upisiOcjenu(int index, int ocjena)
{
    for (int i=0; i<brojStudenata; i++)
        if (studenti[i]->vratiIndex() == index)
        {
            studenti[i]->upisiOcjenu(ocjena);
            return ;
        }
    throw "Nema studenta s tim brojem indexa!";
}
void StudentskaSluzba::ispisiSpisak()
{
    for (int i=0; i<brojStudenata; i++) studenti[i]->ispisiPodatke();
}
int main()
{
    try
    {
        StudentskaSluzba pmf(1000);
        pmf.upisiStudenta(11,"Ivo","Ivic",6);
        pmf.upisiStudenta(12,"Meho","Mehic",1998);
        pmf.upisiStudenta(13,"Vaso","Vasic",7);
        pmf.upisiStudenta(14,"Ibro","Ibric",6);
        pmf.upisiStudenta(15,"Marko","Markovic",2001);
        pmf.upisiOcjenu(11,8);
        pmf.upisiOcjenu(11,7);
        pmf.upisiOcjenu(11,9);
        pmf.upisiOcjenu(12,7);
        pmf.upisiOcjenu(12,8);
        pmf.upisiOcjenu(13,6);
        pmf.upisiOcjenu(13,10);
        pmf.upisiOcjenu(14,7);
        pmf.upisiOcjenu(14,8);
        pmf.upisiOcjenu(14,8);
        pmf.upisiOcjenu(15,9);
        pmf.ispisiSpisak();
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
        cout << "Neki problemi..."  << endl;
    }

    return 0;
}
