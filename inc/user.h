#ifndef USER_H
#define USER_H

#include <string>


// Klasa bazowa User reprezentujaca uzytkownika, zawiera dane logowania i weryfikacje
class User {
protected:
    std::string login;
    std::string password;

public:
    // Konstruktor klasy User   
    User(std::string login, std::string password);    

    // Metoda weryfikuje poprawnosc danych logowania
    bool verification(std::string l, std::string p) const; 
    
    // Gettery
    std::string getLogin() const;   
    std::string getPassword() const;    
    
};

#endif