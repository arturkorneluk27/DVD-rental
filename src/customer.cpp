#include "customer.h"
#include "DVD.h"
#include "admin.h"
#include <iostream>
using namespace std;

Customer::Customer(int id, string name, string surname, string login, string password) : User(login, password), id(id), name(name), surname(surname) {}

void Customer::displayInfo() const {
    cout<<"\nID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Surname: "<<surname<<endl;
    cout<<"Login: "<<login<<endl;
    cout<<"Password: "<<password<<endl;
    cout<<endl;
}

int Customer::getId() const {
    return id;
}

string Customer::getName() const {
    return name;
}

string Customer::getSurname() const {
    return surname;
}



//======================    Wypozycz, zwroc, pokaz    ==============================//



    void Customer::addRental(int dvdId) {
        // Tworzy nowy obiekt Rental i dodaje na koniec wektora
        rentedMovies.push_back(Rental(dvdId));
    }


    bool Customer::hasRented(int dvdId) const {
        // Przeszukuje wektor wypozyczen
        for(const Rental &rental : rentedMovies) {
            if(rental.getDvdID() == dvdId) {
                // Klient wypozyczył Ten film
                return true;        
            }
        }
        // Klient nie wypozyczyl
        return false;
    }


//==================================================================================================



    bool Customer::returnRental(int dvdId) {
        for(auto it = rentedMovies.begin(); it != rentedMovies.end(); ++it) {
            // Porównuje ID filmu, na który wskazuje iterator, z ID filmu do zwrotu
            if(it->getDvdID() == dvdId) {
                // Usuwa film z listy wypozyczonych
                rentedMovies.erase(it);
                return true;
            }
        }
        return false;
    }



//========================================================================================



// Zwraca wskaznik do odczytu / Szuka wypozyczenia o konkretnym dvdId
const Rental* Customer::getRental(int dvdId) const {
    for(const Rental &rental : rentedMovies) {
        if(rental.getDvdID() == dvdId) {
            // Zwraca adres znalezionego wypozyczenia
            return &rental;
        }
    }
    // Wskaznik pusty (nie znaleziono)
    return nullptr;
}



//=================================================================================================


// Zwraca referencje dla calego wektora - wszystkie wypozyczenia
const vector<Rental> &Customer::getRentedMovies() const {
        return rentedMovies;
}


//========================================================================================


    void Customer::showRentals(const vector<DVD> &movies) const {
        if(rentedMovies.empty()) {
            cout<<"Brak wypozyczonych filmow"<<endl;
            return;
        }
        cout<<"Lista wypozyczonych filmow: "<<endl;
        // Przechodzi po wszystkich wypożyczonych przez klienta filmach 
        for(const Rental &rental : rentedMovies) {
            for(const DVD &m : movies)  {
                // Poszukuje obiektu DVD, który odpowiada wypożyczeniu
                if(m.getId() == rental.getDvdID()) {
                    m.displayInfo();
                    break;
                }
            }
        }
    }


//=========================================================================================


    void Customer::showRentalsWithDetails(const vector<DVD> &movies) const {
        if(rentedMovies.empty()) {
        cout<<"\nBrak wypozyczonych filmow"<<endl;
        return;
        }

        cout<<"\n===== MOJE WYPOZYCZENIA ======"<<endl;

        // Suma kar dla wszystkich wypozyczen
        int totalFees = 0;
        // Numer porzadkowy na liscie wypozyczen
        int movieNumber = 1;

        // Iteruje przez wszystkie wypozyczenia
        for(const Rental &rental : rentedMovies) {
            for(const DVD &m : movies) {
                // Poszukuje obiektu DVD, który odpowiada wypożyczeniu
                if(m.getId() == rental.getDvdID()) {
                    cout<<"\nFilm #"<<movieNumber++ <<":"<<endl;
                    cout<<"Tytul: "<< m.getTitle() <<endl;
                    cout<<"Wypozyczono: " << rental.getDaysRented() << " dni temu"<<endl;
                   
                    // Dni do konca terminu
                    int daysLeft = Rental::MAX_DAYS - rental.getDaysRented();

                    // Sprawdza status wypozyczenia
                    if(rental.isLate()) {
                        cout<<"Status: **** OPOZNIENIE ****"<<endl;
                        cout<<"Dni po terminie: " << rental.getDaysLate() <<endl;
                        cout<<"Kara: " << rental.lateFee() << " zl" <<endl;
                        // Dodaj kare do sumy
                        totalFees += rental.lateFee();
                        // Ostatni dzien
                    }   else if(daysLeft == 0) {
                            cout<<"Status: Ostatni dzien wypozyczenia!" <<endl;
                            cout<<"Prosze zwrocic dzisiaj!" <<endl;
                    }   else {
                            cout<<"Status: W terminie" <<endl;
                            cout<<"Pozostalo dni do zwrotu: " << daysLeft <<endl;
                    }
                    cout<<"\n------------------------"<<endl;
                    break;
                }
            }
        }
            // Podsumowanie kar
            if(totalFees > 0) {
                cout<<"\n**** SUMA KAR DO ZAPLATY: " << totalFees << " zl ****"<<endl;
            } else {
                cout<<"\nBrak kar. Wszystko w terminie! :)" <<endl;
            }
            cout<<"\n------------------------"<<endl;
    }


//=====================================================================================================================


    void Customer::simulateDay() {
        for(Rental &rental : rentedMovies) {
            rental.addDay();
        }
        cout<<"\n[SYMULACJA] Minal 1 dzien. Wszystkie wypozyczenia zaktualizowane."<<endl;
    }


//=================================================================================================



void Customer::setRentalDays(int dvdID, int days) {
    // Zwieksza licznik dni dla wszystkich wypozyczen
    for(Rental &rental : rentedMovies) {
        // Sprawdza czy aktualne wypożyczenie to to DVD, ktorego dni chcemy ustawić
        if(rental.getDvdID() == dvdID) {
            rental.setDaysRented(days);
            return;
        }
    }
}



//================================================================


bool Customer::hasNoRentals() const {
    return rentedMovies.empty();
}