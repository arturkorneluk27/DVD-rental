#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include <vector>
#include "DVD.h"
#include "customer.h"
#include "admin.h"

// Menu administratora
void showAdminMenu(std::vector<DVD> &movies, std::vector<Customer> &customers);

#endif