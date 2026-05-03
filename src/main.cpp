#include "admin.h"
#include "menu.h"
#include "data.h"

#include <iostream>
#include <vector>
using namespace std;

// Główna funkcja programu - WYPOZYCZALNIA DVD "RETRO"
int main() {
  cout<<endl;

  // Wczytuje liste DVD z pliku movies.txt
  vector<DVD> movies = loadMovies();

  // Wczytuje liste klientow z pliku customers.txt
  vector<Customer> customers = loadCustomers();

  // Wczytuje / dodaje wypozyczenia dla wczytanych klientow
  loadRentals(customers);
  
  // Administrator
  Admin admin("artur", "1234");

  // Główna petla programu
  showMainMenu(movies, customers, admin);

  // Zapiuje aktualny stan DVD do pliku movies.txt
  saveMovies(movies);

  // Zapisuje aktualna liste klientow do pliku customers.txt
  saveCustomers(customers);

  // Zapisuje wypozyczenia do pliku rentals.txt 
  saveRentals(customers);
  
  return 0;
}
