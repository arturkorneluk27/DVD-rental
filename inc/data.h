#ifndef DATA_H
#define DATA_H

#include <vector>
#include "DVD.h"
#include "customer.h"

// Tworzy domyslna liste filmow DVD, gdy brak pliku movies.txt
std::vector<DVD> DVDList();

// Tworzy domyslna liste klientow, gdy brak pliku customers.txt
std::vector<Customer> customerList();


// Zapisuje liste DVD do pliku movies.txt
void saveMovies(const std::vector<DVD> &movies);

// Wczytuje liste DVD z pliku movies.txt
std::vector<DVD> loadMovies();

// Zapisuje liste klientow do pliku customerss.txt
void saveCustomers(const std::vector<Customer> &customers);

// Wczytuje liste klientow z pliku customers.txt
std::vector<Customer> loadCustomers();

// Zapisuje wypozyczenia wszystkich klientow do pliku rentals.txt
void saveRentals(const std::vector<Customer> &customers);

// Wczytuje wypozyczenia z pliku rentals.txt i przypisuje do klientow
void loadRentals(std::vector<Customer> &customers);

#endif