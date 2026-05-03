#include "data.h"
#include "DVD.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// Funkcja DVDList zwraca wektor DVD
vector<DVD> DVDList() {
    // Zmienna dvds jest wektorem, ktory przechowuje obiekty klasy DVD
    vector<DVD> dvds;  

    // W pushback wywolujemy konstruktor klasy DVD
    dvds.push_back(DVD(1, "Matrix",1999, "Fantastycznonaukowy", "Keanu Reeves", "Laurence Fishburne"));
    dvds.push_back(DVD(2, "Uwierz w ducha", 1990, "Dramat", "Patrick Swayze", "Demi Moore"));
    dvds.push_back(DVD(3, "Leon Zawodowiec", 1994, "Akcja", "Jean Reno", "Natalie Portman"));
    dvds.push_back(DVD(4, "Zapach kobiety", 1992, "Dramat", "Al Pacino", "Chris O'Donnell"));
    dvds.push_back(DVD(5, "Siedem", 1995, "Dreszczowiec", "Morgan Freeman", "Brad Pitt" ));
    dvds.push_back(DVD(6, "Piaty element", 1997, "Fantastycznonaukowy", "Bruce Willis", "Milla Jovovich"));
    dvds.push_back(DVD(7, "Piraci z Karaibow: Klatwa Czarnej Perly", 2004, "Przygodowy", "Johnny Depp", "Keira Knightley"));
    dvds.push_back(DVD(8, "Robin Hood: Ksiaze Zlodziei", 1991, "Przygodowy", "Kevin Costner", "Alan Rickman"));
    dvds.push_back(DVD(9, "Bodyguard", 1992, "Dramat", "Whitney Houston", "Kevin Costner"));
    dvds.push_back(DVD(10, "Forrest Gump", 1994, "Dramat", "Tom Hanks", "Robin Wright" ));
    dvds.push_back(DVD(11, "Skazani na Shawshank", 1994, "Dramat", "Morgan Freeman", "Tim Robbins"));
    dvds.push_back(DVD(12, "Wielki Blekit", 1988, "Dramat", "Jean Reno", "Rosanna Arquette"));

    return dvds;
}



//===========================================================================================



// Funkcja customerList zwraca wektor Customer
vector<Customer> customerList() {
    // Zmienna customers jest wektorem, ktory przechowuje obiekty klasy Customer
    vector<Customer> customers;
    customers.push_back(Customer(1, "Artur", "Korneluk", "piwko", "haslo1"));
    customers.push_back(Customer(2, "Krzysztof", "Ornacki", "kris", "haslo2"));
    customers.push_back(Customer(3, "Mateusz", "Polek", "matipolo", "haslo3"));
    customers.push_back(Customer(4, "Karol", "Ozga", "karol", "haslo4"));
    customers.push_back(Customer(5, "Mikolaj", "Polewka", "polewaj", "haslo5"));
    
    return customers;
}



//===================================== ZAPIS/ODCZYT DVD ====================================



// Zapisuje liste DVD do pliku movies.txt
void saveMovies(const vector<DVD> &movies) {
    // Otwiera plik do zapisu / nadpisuje
    ofstream file("movies.txt");
     if(!file) {
        cout<<"\nBlad zapisu! "<<endl;
        return;
    }
    for(const DVD &m : movies) {
        // Zapisuje kazde pole odzielone znakiem |
        file << m.getId() << "|"
             << m.getTitle() << "|"
             << m.getYear() << "|"
             << m.getGenre() << "|"
             << m.getActor1() << "|"
             << m.getActor2() << "|"
             << m.isAvailable()
             << "\n";
    }
}


// Wczytuje liste DVD z pliku movies.txt
vector<DVD> loadMovies() {
    vector<DVD> movies;
    // Otwiera plik do odczytu
    ifstream file("movies.txt");
    if(!file) {
        // Dane domyslne przy pierwszym uruchomieniu
        return DVDList();  
    }

    string line;
    // Czyta plik linia po lini
    while(getline(file, line)) {
        // Zamienia wczytany strumien line w strumien tekstowy
        stringstream ss(line);
        string part;
        int id, year;
        string title, genre, actor1, actor2;
        bool available;
        // Czyta fragment strumienia tekstowego do znaku |
        getline(ss, part, '|'); 
        // Zamienia string na typ int
        id = stoi(part);
        getline(ss, title, '|');
        getline(ss, part, '|'); 
        year = stoi(part);
        getline(ss, genre, '|');
        getline(ss, actor1, '|');
        getline(ss, actor2, '|');
        getline(ss, part); 
        available = stoi(part);

        // Tworzy obiekt DVD z wczytanymi danymi
        DVD dvd(id, title, year, genre, actor1, actor2);
        dvd.setAvailable(available);
        movies.push_back(dvd);
    }
    return movies;
}


//===================================== ZAPIS/ODCZYT CUSTOMERS ========================================



// Zapisuje liste klientow do pliku customerss.txt
void saveCustomers(const vector<Customer>& customers) {
    // Otwiera plik do zapisu
    ofstream file("customers.txt");
     if(!file) {
        cout<<"\nBlad zapisu! "<<endl;
        return;
    }
    for (const Customer& c : customers) {
        file << c.getId() << "|"
             << c.getName() << "|"
             << c.getSurname() << "|"
             << c.getLogin() << "|"
             << c.getPassword()
             << "\n";
    }
}


// Wczytuje liste klientow z pliku customers.txt
vector<Customer> loadCustomers() {
    vector<Customer> customers;
    // Otwiera plik do odczytu
    ifstream file("customers.txt");
    if (!file) {
        // Dane domyślne przy pierwszym uruchomieniu
        return customerList();  
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string part;
        int id;
        string name, surname, login, password;
        // Czyta fragment strumienia tekstowego do znaku |
        getline(ss, part, '|'); 
        // Zamienia string na typ int
        id = stoi(part);
        getline(ss, name, '|');
        getline(ss, surname, '|');
        getline(ss, login, '|');
        getline(ss, password);
        // Tworzy klienta i dodaje do wektora
        customers.emplace_back(id, name, surname, login, password);
    }
    return customers;
}


//========================== ZAPIS / ODCZYT RENTALS =============================



// Zapisuje wypozyczenia wszystkich klientow do pliku rentals.txt
void saveRentals(const vector<Customer> &customers) {
    ofstream file("rentals.txt");
    if(!file) {
        cout<<"\nBlad zapisu! "<<endl;
        return;
    }
    // Iteruje po klientach
    for(const Customer &c : customers) {
        // Najpierw po ID klienta
        file << c.getId();

        // Pobiera wszystkie wypozyczenia tego klienta (customer.cpp)
        const vector<Rental> &rentals = c.getRentedMovies();
        
        // Zapisuje dvdID i DaysRented dla kazdego klienta
        for(const Rental &r : rentals) {
            file<<"|" <<r.getDvdID() <<"," <<r.getDaysRented();
        }
        // Nastepny klient
        file<<"\n";
    }
    file.close();
}


// Wczytuje wypozyczenia z pliku rentals.txt i przypisuje do klientow
void loadRentals(std::vector<Customer> &customers) {
    ifstream file("rentals.txt");
    if(!file) {
        return;
    } 
        string line;

    // Czyta linia po lini
    while(getline(file, line)) {
        if(line.empty()) continue;
        
        // Zamienia wczytany strumien line w strumien tekstowy
        stringstream ss(line);
        string part;
        
        // Pierwszy element to customerID
        getline(ss, part, '|');
        // Konwersja na int
        int customerId = stoi(part);
        
        // Znajduje klienta
        Customer* customer = nullptr;
        for(Customer &c : customers) {
            if(c.getId() == customerId) {
                // Przypisuje adres znalezionego klienta
                customer = &c;
                break;
            }
        }
        
        if(!customer) {
            continue;
        }
        

        // Wczytuje wypożyczenia
        while(getline(ss, part, '|')) {
            // Pomija puste fragmenty
            if(part.empty()) continue;
            
            // Szuka przecinka, zapisuje index do index ("12,5" -> index = 2)
            size_t index = part.find(',');
            // Sprawdza czy przecinek istnieje
            if(index != string::npos) {
                // Wycina fragment od poczatku do przecinka
                int dvdId = stoi(part.substr(0, index));
                // tekst za przecinkiem
                int daysRented = stoi(part.substr(index + 1));
                
                // Dodaje wypozyczenia do klienta, wywolanie metody przez wskaznik
                customer->addRental(dvdId);

                // Ustawia prawdziwa liczbe dni, przez ktore klient wypozyczyl dany film
                customer->setRentalDays(dvdId, daysRented);
            }
        }
    }
    file.close();
}