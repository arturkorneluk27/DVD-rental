#include "rental.h"
#include <iostream>
using namespace std;

Rental::Rental(int dvdID) : dvdID(dvdID), daysRented(0) {}

int Rental::getDvdID() const {
    return dvdID;
}

int Rental::getDaysRented() const {
    return daysRented;
}


void Rental::addDay() {
    daysRented++;
}

void Rental::setDaysRented(int days) {
    // Ustawia bezposrednio liczbe dni dla wypozyczenia
    daysRented = days;
}


bool Rental::isLate() const {
    return daysRented > MAX_DAYS;
}

int Rental::getDaysLate() const {
    if(!isLate()){
        return 0;
    }
    // Zwraca liczbe dodatnia
    return daysRented - MAX_DAYS;
}

int Rental::lateFee() const {
    return getDaysLate() * LATE_FEE_PER_DAY;
}