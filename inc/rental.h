#ifndef RENTAL_H
#define RENTAL_H

// Klasa Rental reprezentujaca pojedyncze wypozyczenie DVD przez klienta
class Rental {
private:
    // ID wypozyczonego DVD
    int dvdID;

    // Liczba dni wypozyczenia
    int daysRented;

public:
    // Maksymalny czas wypozyczenia (7 dni)
    static const int MAX_DAYS = 7;

    // Kara za kazdy dzien opoznienia (2zl)
    static const int LATE_FEE_PER_DAY = 2;

    //Konstruktor
    Rental(int dvdID);

    // Gettery 
    int getDvdID() const;
    int getDaysRented() const;

    // Setter (przy wczytaniu z pliku) custoper.cpp
    void setDaysRented(int days);

    // Zwieksza dzien wypozyczenia
    void addDay();

    // Sprawdza czy wypozyczenie jest opoznione
    bool isLate() const;

    // Oblicza liczbe dni opoznienia
    int getDaysLate() const;

    // Oblicza wysokosc kary za opoznienie
    int lateFee() const;

};

#endif