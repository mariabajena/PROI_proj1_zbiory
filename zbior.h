#include <iostream>
#include<list>
#include<stdlib.h>

using namespace std;

//klasa, ktorej obiekty reprezentuja punkty o wsp x i y
class Punkt
{
	int x, y; //wspolrzedne punktu
	public:
	Punkt(int wartx=0, int warty=0); //konstruktor
	friend ostream& operator<<(ostream& out, Punkt& punkt); //przeciazanie operatora drukowania do strumienia dla punktu
    friend bool czyRowne(Punkt p1, Punkt p2); //funkcja sprawdzenie, czy dwa podane punkty maja rowne wartosci x i y
    friend int kwOdl(Punkt p1, Punkt p2); //funkcja wyznaczenie kwadratu odleglosci pomiedzy dwoma podanymi punktami
    ~Punkt(); //destruktor
};

//klasa, ktorej obiekty reprezentuja zbior punktow o wsp x i y
class Zbior
{
        string nazwa; //nazwa zbioru
        list <Punkt> lista; //lista przechowujaca punkty zbioru
    public:
        Zbior(string n); //konstruktor
        friend ostream& operator<<(ostream& out, Zbior& zbior); //funkcja przeciazanie operatora drukowania do strumienia dla zbioru
        void wyswietl(); //funkcja wyswietlanie zawartosci zbioru
        bool dodaj(Punkt p); //funkcja dodajaca punkt do zbioru (jesli dwa punkty sa rowne - nie dodaje ich do zbioru)
        friend void suma(Zbior z1, Zbior z2); //funkcja wyznaczanie sumy logicznej dwoch podanych zbiorow
        friend Zbior operator+(Zbior z1, Zbior z2); //przeciazenie operatora +
        friend Zbior operator+=(Zbior z1, Zbior z2); //przeciazenie operatora +=
        friend void iloczyn(Zbior z1, Zbior z2); //funkcja wyznaczanie iloczynu logicznego dwoch podanych zbiorow
        friend Zbior operator*(Zbior z1, Zbior z2);//przeciazenie operatora *
        friend Zbior operator*=(Zbior z1, Zbior z2);//przeciazenie operatora *=
        void najbPunkt(); //funkcja wyznaczanie i wypisanie dwoch lezacych najblizej siebie punktow w zbiorze
        ~Zbior(); //destruktor
};

ostream& operator<<(ostream& out, Punkt& punkt); //przeciazanie operatora drukowania do strumienia
