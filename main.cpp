#include <iostream>
#include <queue>
#include <windows.h>
using namespace std;
//---------------------------------------------------------------
// Klasa Vozilo
//---------------------------------------------------------------
class Vozilo
{
public:
virtual ~Vozilo()
{}
virtual string Vrsta() const = 0;
virtual int BrojProzora() const = 0;
virtual int BrojTockova() const = 0;
virtual int BrojSedista() const = 0;
};
//---------------------------------------------------------------
// Klasa Automobil
//---------------------------------------------------------------
class Automobil : public Vozilo
{
public:
virtual string Vrsta() const            //redefinisanje metoda
{ return "Automobil"; }
virtual int BrojProzora() const
{ return 6; }
virtual int BrojTockova() const
{ return 4; }
virtual int BrojSedista() const
{ return 4; }
};
//---------------------------------------------------------------
// Klasa Kupe
//---------------------------------------------------------------
class Kupe : public Vozilo
{
public:
string Vrsta() const
{ return "Kupe"; }
int BrojTockova() const
{ return 4; }
int BrojProzora() const
{ return 4; }
int BrojSedista() const
{ return 2; }
};
//---------------------------------------------------------------
// Klasa Kamion
//---------------------------------------------------------------
class Kamion : public Vozilo
{
public:
string Vrsta() const
{ return "Kamion"; }
int BrojProzora() const
{ return 4; }
int BrojTockova() const
{ return 6; }
int BrojSedista() const
{ return 2; }
};
//---------------------------------------------------------------
// Klasa Kombi
//---------------------------------------------------------------
class Kombi : public Vozilo
{
public:
string Vrsta() const
{ return "Kombi"; }
int BrojProzora() const
{ return 10; }
int BrojTockova() const
{ return 4; }
int BrojSedista() const
{ return 10; }
};
//---------------------------------------------------------------
// Klasa Karavan
//---------------------------------------------------------------
class Karavan : public Vozilo
{
public:
string Vrsta() const
{ return "Karavan"; }
int BrojProzora() const
{ return 8; }
int BrojTockova() const
{ return 4; }
int BrojSedista() const
{ return 4; }
};
//---------------------------------------------------------------
// Klasa Perionica.
//---------------------------------------------------------------
class Perionica
{
    public:
Perionica()
{}
~Perionica()
{ IsprazniRed(); }
void DodajVoziloURed( Vozilo* v )
{ red.push(v); }
bool ImaVozilaURedu() const
{ return !red.empty(); }
void OperiPrvoVozilo()
{
if( ImaVozilaURedu() ){
Vozilo* v = IzdvojiPrvoVozilo();
cout<< "Na redu je jedan "
<< v->Vrsta() << "." << endl;

Sleep(1000);

cout<< "   - U toku je pranje prozora, ima ih "
<< v->BrojProzora() << endl;

Sleep(1000);

cout<< "   - Trenutno se peru tockovi, ima ih "
<< v->BrojTockova() << endl;

Sleep(1000);

cout<< "   - U toku je pranje sedista, ima ih "
<< v->BrojSedista() << endl;

Sleep(1000);

cout<< "   - Vozilo je oprano." << endl;
delete v;
}
}
private:
Perionica( const Perionica& );
Perionica& operator=( const Perionica& );
void IsprazniRed()
{
while( ImaVozilaURedu() )
delete IzdvojiPrvoVozilo();
}
Vozilo* IzdvojiPrvoVozilo()
{
Vozilo* v = red.front();
red.pop();
return v;
}
queue<Vozilo*> red;
};
//---------------------------------------------------------------
// Glavna funkcija programa demonstrira rad perionice.
//---------------------------------------------------------------
main(){
Perionica sekula;
cout << "Dodajte vozila koja pristizu u perionicu, a ona ce biti oprana po redu."<<endl;
cout << "automobil/kupe/kamion/kombi/karavan" << endl;
cout << "Koliko vozila je na cekanju?" << endl;
string prevoznoSredstvo;
int brojac;
cin >> brojac;
cout << "Unesite vrste vozila:" << endl;
for(int i=0;i<brojac;i++){
cin >> prevoznoSredstvo;
if (prevoznoSredstvo=="automobil"){
sekula.DodajVoziloURed( new Automobil() );
}
if (prevoznoSredstvo=="kupe"){
sekula.DodajVoziloURed( new Kupe() );
}
if (prevoznoSredstvo=="kamion"){
sekula.DodajVoziloURed( new Kamion() );
}
if (prevoznoSredstvo=="kombi"){
sekula.DodajVoziloURed( new Kombi() );
}
if (prevoznoSredstvo=="karavan"){
sekula.DodajVoziloURed( new Karavan() );
}
}
while( sekula.ImaVozilaURedu() ){
sekula.OperiPrvoVozilo();
Sleep(3000);
}
return 0;
}
