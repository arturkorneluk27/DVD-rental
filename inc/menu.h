#ifndef MENU_H
#define MENU_H

#include <vector>
#include "DVD.h"
#include "customer.h"
#include "admin.h"

// Menu główne programu
void showMainMenu(std::vector<DVD> &movies, std::vector<Customer> &customers, Admin &admin);    

// Wyswietla katalog filmow dla niezalogowanych gosci
void showGuestMenu(const std::vector<DVD> &movies);

#endif