#include <iostream>
#include<list>
#include "zbior.h"

using namespace std;

//tworzenie przykladowych zbiorow
Zbior A("A");
Zbior B("B");

//tworzenie przykladowych punktow
Punkt a(10, 10);
Punkt b(1,1);
Punkt c(2,2);
Punkt d(8,8);
Punkt e(4,4);

int wybor,w;

int main() {
    A.dodaj(a);

	B.dodaj(a);
	B.dodaj(b);
	B.dodaj(d);
	B.dodaj(c);
	B.dodaj(e);
	do
        {
        cout << " MENU GLOWNE:"<<endl;
        cout << "---------------------------"<<endl;
        cout << "1.  wyswietl zawartosc"<<endl;
        cout << "2.  wskaz punkty lezace najblizej siebie w zbiorze"<<endl;
        cout << "3.  dodaj punkt do zbioru"<<endl;
        cout << "4.  wyznacz sume logiczna zbiorow"<<endl;
        cout << "5.  wyznacz iloczyn logiczny zbiorow"<<endl;
        cout << "6.  test automatyczny"<<endl;
        cout << "7.  wyjscie"<<endl;
        cout << "---------------------------"<<endl;
        cout << "Wybor: ";
        cin>>wybor;
        while(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Pomylka!"<<endl;
            cin>>wybor;
        }

            switch (wybor)
            {
                case 1:  {
                            A.wyswietl();
                            B.wyswietl();
                         } break;
                case 2:  {
                            cout<<"W ktorym zbiorze chcesz szukac? A---->1, B----->2"<<endl;
                            cin>>w;
                            while(cin.fail()){ //obsluga drukowania strumienia wejsciowego
                                cin.clear();
                                cin.ignore();
                                cout<<"Pomylka!"<<endl;
                                cin>>wybor;
                            }

                            if(w==1) A.najbPunkt();
                            else if(w==2) B.najbPunkt();
                            else cout<<"Pomylka!"<<endl;
                         }  break;
                case 3:  {
                            int x,y;
                            cout<<"Do ktorego zbioru chcesz dodac punkty? A---->1, B----->2"<<endl;
                            cin>>w;
                            while(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout<<"Pomylka!"<<endl;
                                cin>>wybor;
                            }

                            if(w==1) {
                                cout<<"Podaj wspolrzedna x"<<endl;
                                cin>>x;
                            while(cin.fail()){
                                    cin.clear();
                                    cin.ignore();
                                    cout<<"Pomylka!"<<endl;
                                    cin>>wybor;
                                }

                                cout<<"Podaj wspolrzedna y"<<endl;
                                cin>>y;
                                while(cin.fail()){
                                    cin.clear();
                                    cin.ignore();
                                    cout<<"Pomylka!"<<endl;
                                    cin>>wybor;
                                }
                                A.dodaj(Punkt(x,y));
                                cout<<"Punkt ("<<x<<", "<<y<<") zostal dodany do zbioru A."<<endl;
                            }
                            else if(w==2) {
                                cout<<"Podaj wspolrzedna x"<<endl;
                                cin>>x;
                                while(cin.fail()){
                                    cin.clear();
                                    cin.ignore();
                                    cout<<"Pomylka!"<<endl;
                                    cin>>wybor;
                                }
                                cout<<"Podaj wspolrzedna y"<<endl;
                                cin>>y;
                                while(cin.fail()){
                                    cin.clear();
                                    cin.ignore();
                                    cout<<"Pomylka!"<<endl;
                                    cin>>wybor;
                                }
                                B.dodaj(Punkt(x,y));
                                cout<<"Punkt ("<<x<<", "<<y<<") zostal dodany do zbioru B."<<endl;
                                }
                            else cout<<"Pomylka!"<<endl;
                            }break;
                case 4:  suma(A,B);   break;
                case 5:  iloczyn(A,B);       break;
                case 6:  {
                            cout<<"Sprawdzam wszystkie funkcje"<<endl;
                            cout<<endl<<"Wyswietlam zbior A: ";
                            A.wyswietl();
                            cout<<endl<<"Wyswietlam zbior B: ";
                            B.wyswietl();
                            cin.ignore();
                            cout<<endl<<"Wskazuje punkty lezace najblizej siebie w zbiorze A: "<<endl;
                            A.najbPunkt();
                            cout<<endl<<"Wskazuje punkty lezace najblizej siebie w zbiorze B: "<<endl;
                            B.najbPunkt();
                            cin.ignore();
                            cout<<endl<<"Dodaje punkt (7,8) do zbioru A"<<endl;
                            A.dodaj(Punkt(7,8));
                            cout<<"Zbior A po dodaniu punktu (7,8):";
                            A.wyswietl();
                            cin.ignore();
                            cout<<endl<<"Wypisuje sume logiczna zbiorow A i B";
                            suma(A,B);
                            cin.ignore();
                            cout<<endl<<"Wypisuje iloczyn logiczny zbiorow A i B";
                            iloczyn(A,B);
                            cin.ignore();
                            cout<<endl<<"ZAKONCZONO TEST MOZLIWOSCI KLASY"<<endl;
                            cin.ignore();
                        }break;
                case 7:  ;      break;

                default:
                cout<<"POMYLKA!"<<endl;
                break;
            }
            cin.ignore();

        }
        while(wybor!=7);
	return 0;
}
