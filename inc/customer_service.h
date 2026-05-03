#ifndef CUSTOMER_SERVICE_H
#define CUSTOMER_SERVICE_H

#include <vector>
#include "customer.h"
#include "DVD.h"

// Rejestruje nowego uzytkownika w systemie
void registerNewCustomer(std::vector<Customer> &customers);

// Loguje klienta do systemu
Customer* loginCustomer(std::vector<Customer> &customers);

#endif
