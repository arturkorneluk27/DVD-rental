#include "admin_menu.h"
#include "customer.h"
#include "DVD.h"
#include "utils.h"
#include <limits>
#include <iostream>
using namespace std;


void addDVD(vector<DVD> &movies) {
    int id, year;
    string title, genre, actor1, actor2;

    cout<<"\n==== DODANIE NOWEGO DVD ===="<<endl;

    // Przydziela automatycznie nastepne wolne ID
    int nextID = 1;
    if(!movies.empty()) {
        for(const DVD &m : movies) {
            if(m.getId() >= nextID) {
                nextID = m.getId() + 1;
            }
        }
    }
    id = nextID;
    cout<<"ID: " << id <<endl;
    
    //Pobieranie danych
    cout<<"Tytul: ";
    getline(cin, title);

    cout<<"Rok wydania: ";
    year = getInt();

    cout<<"Gatunek: ";
    getline(cin, genre);

    cout<< "Wystepuje (aktor1, aktor2): ";
    // Czyta do przecinka
    getline(cin, actor1, ',');   
    getline(cin, actor2); 

    // Dodanie nowego DVD do wektora
    movies.push_back(DVD(id, title, year, genre, actor1, actor2));

    cout<<"\nDVD zostalo dodane pomyslnie!"<<endl;
    pause();
}


//============================================================



void removeDVD(vector<DVD> &movies) {
    if(movies.empty()) {
        cout<<"\nBrak DVD w bazie!"<<endl;
        pause();
        return;
    }

    cout<<"\n==== USUWANIE DVD ===="<<endl;
    
    cout<<"Lista dostepnych DVD: "<<endl;
    for(const auto &dvd : movies) {
        dvd.displayInfo();
    }

    int id;
    cout<<"Podaj ID DVD do usuniecia (0 = wyjdz bez usuwania): ";
    id = getInt();

    if(id == 0) {
        return;
    }

    // Szuka DVD po ID
   for(auto it = movies.begin(); it != movies.end(); ++it) {
        if(it->getId() == id) {
            // Sprawdza czy DVD nie jest wypozyczone
            if(!it->isAvailable()) {
                cout<< "\nNie mozna usunac DVD - jest aktualnie wypozyczone!\n";
                pause();
                return;
            }
            // Usuwa DVD
            movies.erase(it);
            cout<<"\nDVD o ID "<< id <<" zostalo usuniete.\n";
            pause();
            return;
        }
    }
    cout<<"\nNie znaleziono DVD o podanym ID!\n";
    pause();
}


//========================================================


void editDVD(vector<DVD> &movies) {
     if(movies.empty()) {
        cout<<"\nBrak DVD w bazie!"<<endl;
        pause();
        return;
    }

    cout<<"\n==== EDYTOWANIE DVD ===="<<endl;

    cout<<"Lista dostepnych DVD: "<<endl;
    for(const auto &m : movies) {
        m.displayInfo();
    }

    int id;
    cout<<"Podaj ID DVD do edytowania (0 = wyjdz bez usuwania): ";
    id = getInt();

    if(id == 0) {
        return;
    }

    // Szuka DVD do edycji
    for(auto &dvd : movies) {
        if(dvd.getId() == id) {
            int choice;
            // Różne możliowosci edycji
            cout<<"\n===== EDYCJA DVD o ID: "<< id <<" ====="<<endl;
            cout<<"1. Edytuj tytul" <<endl;
            cout<<"2. Edytuj rok wydania" <<endl;
            cout<<"3. Edytuj gatunek" <<endl;
            cout<<"4. Edytuj aktorow" <<endl;
            cout<<"5. Edytuj wszystko" <<endl;
            cout<<"6. Anuluj" <<endl;
            cout<<"===========================" <<endl;
            cout<<"Wybierz opcje: ";

            choice = getInt();

            switch(choice) {
                case 1: {
                    string newTitle;
                    cout<<"Nowy tytul: ";
                    getline(cin, newTitle);
                    dvd.setTitle(newTitle);
                    cout<<"\nTytul zostal zaktualizowany!"<<endl;
                    break;
                }
                case 2: {
                    int newYear;
                    cout<<"Nowy rok wydania: ";
                    newYear = getInt();
                    dvd.setYear(newYear);
                    cout<<"\nRok wydania zostal zaktualizowany!"<<endl;
                    break;
                }
                case 3: {
                    string newGenre;
                    cout<<"Nowy gatunek: ";
                    getline(cin, newGenre);
                    dvd.setGenre(newGenre);
                    cout<<"\nGatunek zostal zaktualizowany!"<<endl;
                    break;
                }
                case 4: {
                    string newActor1, newActor2;
                    cout<<"Wystepuje (aktor1,aktor2): ";
                    getline(cin, newActor1, ','); 
                    getline(cin, newActor2); 
                    dvd.setActors(newActor1, newActor2);
                    cout<<"\nAktorzy zostali zaktualizowani!"<<endl;
                    break;
                }
                case 5: {
                    string newTitle, newGenre, newActor1, newActor2;
                    int newYear;

                    cout<<"Nowy tytul: ";
                    getline(cin, newTitle);
                    cout<<"Nowy rok wydania: ";
                    newYear = getInt();
                    cin.ignore();
                    cout<<"Nowy gatunek: ";
                    getline(cin, newGenre);
                    cout<<"Wystepuje (aktor1,aktor2): ";
                    getline(cin, newActor1, ',');  
                    getline(cin, newActor2);

                    dvd.setTitle(newTitle);
                    dvd.setYear(newYear);
                    dvd.setGenre(newGenre);
                    dvd.setActors(newActor1, newActor2);
                    cout<<"\nWszystkie dane zostaly zaktualizowane!"<<endl;
                    break;
                }
                case 6:
                    cout<<"\nEdycja anulowana"<<endl;
                    pause();
                    return;
                default:
                    cout<<"\nNiepoprawny wybor"<<endl;
                
            }
            pause();
            return;
        }
    }
    cout<<"\nNIe znaleziono DVD o podanym ID!"<<endl;
    pause();
}


//========================================================


void manageDVDs(vector<DVD> &movies) {
    int choice;

    cout<<"\n===== ZARZADZANIE DVD =====" <<endl;
    cout<<"1. Dodaj nowy DVD" <<endl;
    cout<<"2. Usun DVD" <<endl;
    cout<<"3. Edytuj DVD" <<endl;
    cout<<"4. Powrot" <<endl;
    cout<<"===========================" <<endl;
    cout<<"Wybierz opcje: ";
    choice = getInt();

    switch(choice) {
        case 1: {
            addDVD(movies);
            break;
        }
        case 2: {
            removeDVD(movies);
            break;
        }
        case 3: {
            editDVD(movies);
            break;
        }
        case 4:
            return;
        default:
            cout<<"Niepoprawny wybor." <<endl;
    }
}