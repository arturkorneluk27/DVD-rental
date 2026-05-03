#ifndef CUSTOMER_MENU_H
#define CUSTOMER_MENU_H

#include <vector>
#include "DVD.h"
#include "rental.h"
#include "customer.h"

// Menu wypozyczenia filmu przez klienta
void rentDVDMenu(std::vector<DVD> &movies, Customer &customer);

// Menu zwrotu filmu przez klienta
void returnDVDMenu(std::vector<DVD> &movies, Customer &customer);

// Ogólne menu klienta
void showCustomerMenu(std::vector<DVD> &movies, Customer &customer);

#endif