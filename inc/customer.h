#ifndef Customer_H
#define Customer_H

#include "user.h"
#include "DVD.h"
#include "rental.h"
#include <string>
#include <vector>

// Klasa Customer reprezentujaca klienta wypozyczalni, dziedziczaca po klasie bazowej User
class Customer : public User {
private: 
    int id;
    std::string name;
    std::string surname;
    // Lista wypozyczonych filmow
    std::vector<Rental> rentedMovies; 

public:
    // Konstruktor klasy Customer
    Customer(int id, std::string name, std::string surname, std::string login, std::string password);

    // Gettery
    int getId() const;
    std::string getName() const;
    std::string getSurname() const;

    // Wyswietla pelne informacje o kliencie
    void displayInfo() const;

    // Dodaje nowe wypozyczenie do listy klienta
    void addRental(int dvdId);

    // Sprawdza czy klient wypozyczyl DVD
    bool hasRented(int dvdId) const;

    // Usuwa wypozyczenie z listy klienta (zwrot)
    bool returnRental(int dvdId); 

    // Wyswietla liste wypozyczonych filmow
    void showRentals(const std::vector<DVD> &movies) const;

    // Wyswietla szczegolowa liste wypozyczonych filmow
    void showRentalsWithDetails(const std::vector<DVD> &movies) const;

    // Zwraca wskaznik do wypozyczenia (Rental) - jedno konkretne wypozyczenie
    const Rental* getRental(int dvdId) const;   
    
    // Zwraca caly wektor wypozyczen klienta - wszystkie wypozyczenia
    const std::vector<Rental> &getRentedMovies() const;

    // Znajduje wypozyczenie klienta po ID filmu i wywoluje setDaysRented()
    void setRentalDays(int dvdId, int days);

    // Symuluje uplyw jednego dnia, zwieksza licznik dni dla wszystkich wypozyczen
    void simulateDay(); 

    // Sprawdza czy klient ma pusta liste wypozyczen
    bool hasNoRentals() const;
};

#endif