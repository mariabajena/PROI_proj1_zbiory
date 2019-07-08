#include <iostream>
#include<list>
#include "zbior.h"

using namespace std;

//konstruktor klasy Punkt
Punkt::Punkt(int wartx, int warty){
        x=wartx;
        y=warty;
}

//destruktor klasy Punkt
Punkt::~Punkt(){}

//konstruktor klasy Zbior
Zbior::Zbior(string n){
    nazwa=n;
}

//destruktor klasy Zbior
Zbior::~Zbior(){}

//funkcja sprawdzenie, czy dwa podane punkty maja rowne wartosci x i y
bool czyRowne(Punkt p1, Punkt p2){
    if((p1.x==p2.x) && (p1.y==p2.y)) return true;
    else return false;
}

//funkcja wyswietlanie zawartosci zbioru
void Zbior::wyswietl(){
     cout<<endl<<nazwa<<": ";
    if(lista.empty()) cout<<"Zbior jest pusty"<<endl;
    else{
        for(list<Punkt>::iterator i=lista.begin(); i!= lista.end(); ++i)
        cout<<*i<<" ";
    }
    cout<<endl;
}

//funkcja dodajaca punkt do zbioru (jesli dwa punkty sa rowne - nie dodaje ich do zbioru)
bool Zbior::dodaj(Punkt p){
    for(list<Punkt>::iterator i=lista.begin(); i!= lista.end(); ++i)
        {
            if(czyRowne((*i),p)){
                return 0;
            }
        }
    lista.push_front(p);
    return 1;
}

//przeciazanie operatora drukowania do strumienia dla punktu
ostream& operator<<(ostream& out, Punkt& punkt){
    out<<"("<<punkt.x<<","<<punkt.y<<")";
    return out;
}

//przeciazanie operatora drukowania do strumienia dla zbioru
ostream& operator<<(ostream& out, Zbior& zbior){
    for(list<Punkt>::iterator i=zbior.lista.begin(); i!= zbior.lista.end(); ++i)
    out<<*i<<" ";
    return out;
}

//przeciazenie operatora +
Zbior operator+(Zbior z1, Zbior z2){
    Zbior Suma("Suma");
    z1.lista.insert(z1.lista.end(), z2.lista.begin(), z2.lista.end());
    for(list<Punkt>::iterator i=z1.lista.begin(); i!= z1.lista.end(); ++i)
    Suma.dodaj((*i));
    return Suma;
}

//przeciazenie operatora +=
Zbior operator+=(Zbior z1, Zbior z2){
    Zbior Suma("Suma");
    z1.lista.insert(z1.lista.end(), z2.lista.begin(), z2.lista.end());
    for(list<Punkt>::iterator i=z1.lista.begin(); i!= z1.lista.end(); ++i)
    Suma.dodaj((*i));
    return Suma;
}

//funkcja wyznaczanie sumy logicznej dwoch podanych zbiorow
void suma(Zbior z1, Zbior z2){
    Zbior Suma("Suma");
    Suma=z1+z2;
    cout<<endl<<"Suma zbiorow "<<z1.nazwa<<" i "<<z2.nazwa<<" wynosi "<<Suma<<endl;
}

//funkcja wyznaczanie iloczynu logicznego dwoch podanych zbiorow
void iloczyn(Zbior z1, Zbior z2){
     Zbior Iloczyn("Iloczyn");
     Iloczyn=z1*z2;
     cout<<endl<<"Iloczyn zbiorow "<<z1.nazwa<<" i "<<z2.nazwa<<" wynosi "<<Iloczyn<<endl;
}

//przeciazenie operatora *
Zbior operator*(Zbior z1, Zbior z2){
     Zbior Iloczyn("Iloczyn");
     for(list<Punkt>::iterator i=z1.lista.begin(); i!= z1.lista.end(); ++i){
       for(list<Punkt>::iterator j=z2.lista.begin(); j!= z2.lista.end(); ++j){
                    if(czyRowne((*i), (*j))) Iloczyn.lista.push_front((*i));
            }
    }
    return Iloczyn;
}

//przeciazenie operatora *=
Zbior operator*=(Zbior z1, Zbior z2){
     Zbior Iloczyn("Iloczyn");
     for(list<Punkt>::iterator i=z1.lista.begin(); i!= z1.lista.end(); ++i){
       for(list<Punkt>::iterator j=z2.lista.begin(); j!= z2.lista.end(); ++j){
                    if(czyRowne((*i), (*j))) Iloczyn.lista.push_front((*i));
            }
    }
    return Iloczyn;
}

//funkcja wyznaczenie kwadratu odleglosci pomiedzy dwoma podanymi punktami
int kwOdl(Punkt p1, Punkt p2){
    int odl=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
    return odl;
}

//funkcja wyznaczanie i wypisanie dwoch lezacych najblizej siebie punktow w zbiorze
void Zbior::najbPunkt(){
    int min;
    if(czyRowne(lista.back(),lista.front())){
        cout<<"W zbiorze "<<nazwa<<" jest tylko 1 punkt."<<endl;
        return;
    }
    min=kwOdl(lista.back(),lista.front());
    Zbior ZNajb("ZNajb");
    ZNajb.lista.push_front(lista.front());
    ZNajb.lista.push_back(lista.back());
    for(list<Punkt>::iterator i=lista.begin(); i!= lista.end(); ++i){
       for(list<Punkt>::iterator j=lista.begin(); j!= lista.end(); ++j){
                if(!czyRowne((*i),(*j))){
                    if(kwOdl((*i),(*j))<min){
                            min=kwOdl((*i),(*j));
                            ZNajb.lista.push_front((*i));
                            ZNajb.lista.push_back((*j));
                    }
           }
        }
    }
    cout<<"Punkty polozone najblizej siebie w zbiorze "<<nazwa<<" to: "<<ZNajb.lista.front()<<" i "<<ZNajb.lista.back()<<endl;
}

