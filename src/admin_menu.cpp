#include <iostream>
#include <limits>
using namespace std;

#include "admin_menu.h"
#include "admin_DVD_menu.h"
#include "admin_customer_menu.h"
#include "utils.h"



void showAdminMenu(vector<DVD> &movies, vector<Customer> &customers) {
    int choice;
    
    while(true) {
        cout<<"\n========= MENU ADMINISTRATORA ========="<<endl;
        cout<<"1. Zarzadzaj DVD" <<endl;
        cout<<"2. Zarzadzaj klientami"<<endl;
        cout<<"3. Wyswietl wszystkie DVD"<<endl;
        cout<<"4. Wyswietl wszystkich klientow"<<endl;
        cout<<"5. Wyloguj" <<endl;
        cout<<"=======================================" <<endl;
        cout<<"Wybierz opcje: ";
        choice = getInt();
        cout<<endl;

        switch(choice) {
            case 1:
                // admin_DVD_menu.cpp
                manageDVDs(movies);
                break;
            case 2:
                manageCustomers(customers);
                break;
            case 3:
                cout<<"\n==== LISTA WSZYSTKICH DVD ===="<<endl;
                for(DVD &m : movies) {
                    m.displayInfo();
                }
                pause();
                break;
            case 4:
                cout<<"\n==== LISTA WSZYSTKICH KLIENTOW ===="<<endl;
                if(customers.empty()) {
                    cout<<"Brak zarejestrowanych klientow" <<endl;
                } else {
                    for(const Customer &c : customers) {
                        c.displayInfo();
                        cout<<"------------------------"<<endl;
                    }
                }
                pause();
                break;    
            case 5:
                cout<<"Wylogowano."<<endl;
                return;
            default:
                cout<<"Niepoprawny wybor."<<endl;
        }
    }
}

