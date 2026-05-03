#include "customer.h"
#include "utils.h"
#include <limits>

#include <iostream>
using namespace std;


void addCustomer(vector<Customer> &customers) {
    int id;
    string name, surname, login, password;

    cout<<"\n==== DODANIE NOWEGO KLIENTA ===="<<endl;
    
    // Przydziela automatycznie ID
    int nextID = 1;
    if(!customers.empty()) {
        for(const Customer &c : customers) {
            if(c.getId() >= nextID) {
                nextID = c.getId() + 1;
            }
        }
    }

    id = nextID;
    cout<<"ID: " << id <<endl; 

    cout<<"Imie: ";
    getline(cin, name);

    cout<<"Nazwisko: ";
    getline(cin, surname);

    cout<<"Login: ";
    getline(cin, login);

    cout<<"Password: ";
    getline(cin, password);

    for(const Customer &c : customers) {
        if(c.getLogin() == login) {
            cout<<"\nLogin juz istnieje!"<<endl;
            pause();
            return;
        }
    }

    // Tworzy nowy obiekt Customer i dodaje do wektora
    customers.push_back(Customer(id, name, surname, login, password));

    cout<<"Klient zostal dodany pomyslnie!" <<endl;
    pause();
}


//=======================================================



void removeCustomer(vector<Customer> &customers) {
    if(customers.empty()) {
        cout<<"\nBrak klientow w bazie!"<<endl;
        pause();
        return;
    }

    cout<<"\n==== USUWANIE KLIENTA ===="<<endl;
    cout<<"Lista dostepnych klientow: "<<endl;
    
    for(auto &c : customers) {
        c.displayInfo();
    }

    // Pobiera ID klienta do usuniecia
    int id;
    cout<<"Podaj numer klienta do usuniecia (0 = wyjdz bez usuwania): ";
    id = getInt();

    // Anulowanie
    if(id == 0) {
        return;
    }

   for(auto it = customers.begin(); it != customers.end(); ++it) {
        if(it->getId() == id) {
            if(!it->hasNoRentals()) {
                cout<< "\nNie mozna usunac klienta - posiada aktywne wypozyczenia!\n";
                pause();
                return;
            }
            // Usuwa klienta 
            customers.erase(it);
            cout<<"\nKlient o ID "<< id <<" zostal usuniety."<<endl;
            pause();
            return;
        }
    }
    cout<<"\nNie znaleziono klienta o podanym ID!"<<endl;
    pause();
}


//============================================================



void manageCustomers(vector<Customer> &customers) {
    int choice;

    cout<<"\n===== ZARZADZANIE KLIENTAMI =====" <<endl;
    cout<<"1. Dodaj nowego klienta" <<endl;
    cout<<"2. Usun klienta (ban)" <<endl;
    cout<<"3. Powrot" <<endl;
    cout<<"=================================" <<endl;
    cout<<"Wybierz opcje: ";
    choice = getInt();

    switch(choice) {
        case 1: {
            addCustomer(customers);
            break;
        }
        case 2: {
            removeCustomer(customers);
            break;
        }
        case 3:
            return;
        default:
            cout<<"Niepoprawny wybor." <<endl;
    }
}
