#include "DVD.h"
#include "menu.h"
#include "admin.h"
#include "customer.h"
#include "customer_menu.h"
#include "admin_menu.h"
#include "utils.h"
#include "customer_service.h"
#include "search_menu.h"
#include "search.h"
#include <iostream>
using namespace std;



void showMainMenu(vector<DVD> &movies, vector<Customer> &customers, Admin &admin) {
    int choice;

    // Główna petla programu
    while(true) {
        cout<<"\n=====================================================" <<endl;
        cout<<"             WYPOZYCZALNIA DVD \"RETRO\"         "<<endl;
        cout<<"=====================================================" <<endl;
        cout<<"1. Logowanie administratora" <<endl;
        cout<<"2. Logowanie klienta" <<endl;
        cout<<"3. Rejestracja nowego klienta"<<endl;
        cout<<"4. Przegladaj oferte (bez logowania)" <<endl;
        cout<<"5. Wyszukaj film"<<endl;
        cout<<"6. Wyjscie" <<endl;
        cout<<"=====================================================" <<endl;
        cout<<"Wybierz opcje: ";
        choice = getInt();
        cout<<endl;

        switch(choice) {
            case 1: {
                // logowanie administratora
                if(admin.loginAdmin()) {
                    showAdminMenu(movies, customers);
                }
                break;
            }
            case 2: {
                // Zmienna logged przechowuje adres klienta
                Customer* logged = loginCustomer(customers);
                //nullptr - logowanie nieudane
                if(logged != nullptr) {
                    //*logged - dereferencja wskaznika (sięgamy po obiekt)
                    showCustomerMenu(movies, *logged);
                }
                break;
            }
            case 3: {
                // Rejestracja nowego uzytkownika
                registerNewCustomer(customers);
                break;
            }
            case 4:
                showGuestMenu(movies);
                pause();
                break;
            case 5:
                // Menu wyszukiwania
                searchDVD(movies);
                break;
            case 6:
                // Wyjscie z programu
                cout<<"Do widzenia!\n" <<endl;
                return;
            default:
                cout<< "Niepoprawny wybor. Sprobuj ponownie." << endl;
                pause();
        }
    }
}


//==================================================


void showGuestMenu(const vector<DVD> &movies) {
    cout<<"\n==== DOSTEPNE FILMY ====" <<endl;
    // Wyswietla wszystkie filmy
    for(const DVD &m : movies) {
        m.displayInfo(); 
    }
    cout<<"\nJesli chcesz wypozyczyc DVD, zaloz konto a nastepnie zaloguj sie :)"<<endl;
}

