#ifndef ADMIN_CUSTOMER_MENU_H
#define ADMIN_CUSTOMER_MENU_H

#include "customer.h"

// Dodaje nowego klienta do systemu
void addCustomer(std::vector<Customer> &customers);

// Usuwa klienta z systemu
void removeCustomer(std::vector<Customer> &customers);

// Menu zarzadzania klientami
void manageCustomers(std::vector<Customer> &customers);

#endif