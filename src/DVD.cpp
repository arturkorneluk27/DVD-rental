#include "DVD.h"
#include "customer.h"
#include <iostream>
using namespace std;

// Konstruktor klasy DVD                               
DVD::DVD(int id, string title, int year, string genre, string actor1, string actor2) : id(id), title(title), year(year), genre(genre), actor1(actor1), actor2(actor2), available(true) {}

void DVD::displayInfo() const {
   
   cout<<"\nID: "<< id <<endl;
   cout<< "Tytul: " << title <<endl;
   cout<< "Rok wydania: " << year <<endl;
   cout<< "Gatunek: " << genre <<endl;
   cout<< "Wystepuja: " << actor1 <<", "<< actor2 <<endl;

    if(available)
        cout<< "Dostepny: tak";
    else 
        cout<<"Dostepny: nie";
        
        cout<<"\n";
        cout<<"\n------------------------"<<endl;
}


bool DVD::isAvailable() const {   
    return available; 
}

int DVD::getId() const {
    return id;
}

string DVD::getTitle() const {
    return title;
}

int DVD::getYear() const {
    return year;
}

string DVD::getGenre() const {
    return genre;
}

string DVD::getActor1() const {
    return actor1;
}

string DVD::getActor2() const{
    return actor2;
}



void DVD::setAvailable(bool status) { 
    available = status; 
}

void DVD::setTitle(string newTitle) {
    title = newTitle;
}

void DVD::setYear(int newYear) {
    year = newYear;
}

void DVD::setGenre(string newGenre) {
    genre = newGenre;
}

void DVD::setActors(string newActor1, string newActor2) {
    actor1 = newActor1;
    actor2 = newActor2;
}