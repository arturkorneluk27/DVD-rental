#include "customer_service.h"
#include "customer_menu.h"
#include "utils.h"
#include <string>
#include <iostream>
using namespace std;

void registerNewCustomer(std::vector<Customer> &customers) {
    int id;
    string name, surname, login, password, confirmPassword;

    cout<<"\n==== REJESTRACJA NOWEGO KLIENTA ===="<<endl;
    cout<<"Prosze wypelnic dane rejestracyjne."<<endl;

    // Przydziela automatycznie kolejne ID
    int nextID = 1;

    if(!customers.empty()) {
        for(const Customer &c : customers) {
            // Znajdz najwieksze ID i dodaj 1
            if(c.getId() >= nextID) {
                nextID = c.getId() + 1;
            }
        }
    }
    // Przypisz ID
    id=nextID;

    cout<<"Imie: ";
    getline(cin, name);

    if(name.empty()) {
        cout<<"\nTo pole nie moze byc puste!"<<endl;
        pause();
        return;
    }
    
    cout<<"Nazwisko: ";
    getline(cin, surname);
    
    if(surname.empty()) {
        cout<<"\nTo pole nie moze byc puste!"<<endl;
        pause();
        return;
    }

    while(true) {
        cout<<"Login (min. 4 znaki): ";
        getline(cin, login);

        // Sprawdza dlugosc loginu
        if(login.length() < 4) {
            cout<<"Login musi miec co najmniej 4 znaki!"<<endl;
            continue;
        }

        // Sprawdza czy login juz istnieje
        bool loginExists = false;
        for(const Customer &c : customers) {
            if(c.getLogin() == login) {
                loginExists = true;
                break;
            }
        }
        
        if(loginExists) {
            cout<<"Login juz istnieje! Wybierz inny." <<endl;
            continue;
        }
        // Dobry login
        break;
    }

    while(true) {
        cout<<"Haslo (min. 4 znaki): ";
        getline(cin, password);
        
        // Sprawdza dlugosc hasla
        if(password.length() < 4) {
            cout<<"Haslo musi miec co najmniej 4 znaki!"<<endl;
            continue;
        }
        
        cout<<"Potwierdz haslo: ";
        getline(cin, confirmPassword);
        
        // Sprawdza czy hasla sa identyczne
        if(password != confirmPassword) {
            cout<<"\nHasla nie sa identyczne! Sprobuj ponownie"<<endl;
            cout<<endl;
            continue;
        }
        
        // Dobre haslo
        break; 
    }

    // Tworzy nowy obiekt Customer i dodaje do wektora 
    customers.push_back(Customer(id, name, surname, login, password));

    cout<<"\nKonto zostalo utworzone pomyslnie!"<<endl;
    cout<<"\n========================================="<<endl;
    cout<<"Twoje dane logowania:"<<endl;
    cout<<"Login: " << login <<endl;
    cout<<"ID klienta: " << id <<endl;
    cout<<"========================================="<<endl;
    cout<<"\nMozesz sie teraz zalogowac w menu glownym."<<endl;
    
    pause();
}


//=====================================================================



// Funkcja zwraca wskaznik do obiektu klasy Customer w wektorze (bez kopiowania)
Customer* loginCustomer(std::vector<Customer> &customers) {
    string login, password;
    cout<<"==== LOGOWANIE KLIENTA ===="<<endl;
    cout<<"Login: ";
    cin>>login;
    cout<<"Password: ";
    cin>>password;

    // Przeszukuje wszystkich klientow
    for(Customer &c : customers) {
        // Sprawdza czy login i haslo sie zgadzaja
        if(c.verification(login, password)) {
            cout<<"\nWitaj, "<< c.getName() << "!" <<endl;
            // Adres klienta
            return &c;
        }
    }

    cout<< "\nNiepoprawny login lub haslo!" <<endl;  
    return nullptr;         
}