#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include <iostream>

// Klasa Admin reprezentujaca administratora, dziedziczaca po klasie bazowej User
class Admin : public User {
public:
    Admin(std::string login, std::string password);  
   
    // Wyswietla podstawowe informacje o administratorze
    void displayInfo() const;

    // Logowanie administratora
    bool loginAdmin();

};

#endif