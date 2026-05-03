#include <iostream>
#include <limits>
#include "customer_menu.h"
#include "utils.h"
using namespace std;


void rentDVDMenu(vector<DVD> &movies, Customer &customer) {

     if(movies.empty()) {
        cout<<"Brak DVD do wypozyczenia!"<<endl;
        pause();
        return;
    } 

    cout<<"\n===== WYPOZYCZENIE DVD ====="<<endl;
    cout<<"Dostepne filmy do wypozyczenia: "<<endl;

    // Wyswietla tylko dostepne (niewypozyczone) DVD
    bool anyAvailable = false;
    for(const auto &dvd : movies) {
        if(dvd.isAvailable()) {
            dvd.displayInfo();
            anyAvailable = true; 
        }
    }

    if(!anyAvailable) {
        cout<<"\nBrak dostepnych DVD do wypozyczenia!"<<endl;
        pause();
        return;
    }
    // ID filmu do wypozyczenia
    int id;
    cout<<"\nPodaj ID DVD do wypozyczenia (0 = wyjdz bez wypozyczania): ";
    id = getInt();

    if(id==0) {
        return;
    }
    // Szuka DVD o podanym ID
    for(auto &dvd : movies) {
        if(dvd.getId() == id) {
            if(!dvd.isAvailable()) {
                cout<<"\nTo DVD jest juz wypozyczone!"<<endl;
                pause();
                return;
            }

            // Ustawia DVD jako wypozyczone
            dvd.setAvailable(false);
            // Dodaje wypozyczenie do klienta
            customer.addRental(dvd.getId());

            cout<<"\n============================================"<<endl;
            cout<<"Film  " << dvd.getTitle() <<"  zostal wypozyczony pomyslnie!"<<endl;
            cout<<"Termin zwrotu: za "<< Rental::MAX_DAYS<<" dni"<<endl;
            cout<<"Kara za opoznienie: "<< Rental::LATE_FEE_PER_DAY <<" zl/dzien"<<endl;
            cout<<"============================================="<<endl;
            
            pause();
            return;
        }
    }
    cout<<"\nNie znaleziono DVD o podanym ID!"<<endl;
    pause();
}


//===============================================


void returnDVDMenu(vector<DVD> &movies, Customer &customer) {
    cout<<"\n===== ZWROCENIE DVD ====="<<endl;
    cout<<"Twoje wypozyczone filmy: " <<endl;

    // Wyswietla tylko DVD wypozyczone przez tego klienta
    bool anyRented = false;
    for(const auto &dvd : movies) {
        if(customer.hasRented(dvd.getId())) {
            dvd.displayInfo();
            anyRented = true;
        }
    }

    if(!anyRented) {
        cout<<"\nBrak DVD do zwrocenia!"<<endl;
        pause();
        return;
    }

    // ID filmu do zwrotu
    int id;
    cout<<"\nPodaj ID DVD do zwrocenia (0 = wyjdz bez wypozyczania): ";
    id = getInt();

    if(id==0) {
        return;
    }

    // Sprawdza czy klient wypozyczyl ten film
    if(!customer.hasRented(id)) {
        cout<<"\nNie wypozyczales tego filmu!"<<endl;
        pause();
        return;
    }

    // Pobiera informacje o wypozyczeniu (przed zwrotem)
    const Rental* rental = customer.getRental(id);

    if(!rental) {
        cout<<"\nNie znaleziono wypozyczenia!"<<endl;
        pause();
        return;
    }

    // Zapisuje informacje o karach przed usunieciem wypozyczenia
    bool late = rental->isLate();           
    int daysLate = rental->getDaysLate();
    int fee = rental->lateFee();

    // Zwraca DVD
    bool filmFound = false;
    for(auto &dvd : movies) {
        if(dvd.getId() == id) {
            // Ustawia DVD ponownie jako dostepne
            dvd.setAvailable(true);
            // Usuwa wypozyczenie z listy klienta
            customer.returnRental(id); 
            filmFound = true;
            break;
        }
    }

    if(!filmFound) {
        cout<<"\nNie znaleziono DVD o podanym ID!"<<endl;
        pause();
        return;
    }

    cout<<"\n============================================"<<endl;
    if(late) {
        cout<<"**** UWAGA: OPOZNIENIE ****"<<endl;
        cout<<"Dni opoznienia: "<< daysLate <<endl;
        cout<<"Kara do zaplaty: "<< fee <<" zl"<<endl;
        cout<<"Prosimy o zaplacenie kary przy recepcji!"<<endl;
    } else {
        cout<<"Film zwrocony w terminie. Dziekujemy!"<<endl;
    }
    cout<<"============================================"<<endl;
    
    pause();
}


//=========================================================================


void showCustomerMenu(vector<DVD> &movies, Customer &customer) {
    int choice;

    while(true) {
        cout<<"\n====== MENU KLIENTA ======" <<endl;
        cout<<"1. Przegladaj dostepne filmy"<<endl;
        cout<<"2. Wypozycz DVD"<<endl;
        cout<<"3. Oddaj DVD" <<endl;
        cout<<"4. Moje wypozyczenia (szczegoly)"<<endl;
        cout<<"5. Wyloguj"<<endl;
        cout<<"6. [TEST] Symuluj dzien"<<endl;
        cout<<"==========================" <<endl;
        cout<<"Wybierz opcje: ";
        choice = getInt();
        cout<<endl;

        switch(choice) {
            case 1: 
                cout<<"\n==== DOSTEPNE FILMY ===="<<endl;
                for(const DVD &m : movies) {
                    if(m.isAvailable()) {
                        m.displayInfo();
                    }
                }
                pause();
                break;
            case 2: 
                rentDVDMenu(movies, customer);
                break;
            case 3:
                returnDVDMenu(movies, customer);
                break;
            case 4:
                customer.showRentalsWithDetails(movies);
                pause();
                break;
            case 5:
                cout<<"Wylogowano." <<endl;
                return;
                break;
            case 6:
                // Symuluje uplyw dnia
                customer.simulateDay();
                pause();
            default:
                cout<< "Niepoprawny wybor." <<endl;
        }
    }
}