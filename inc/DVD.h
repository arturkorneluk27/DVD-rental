#ifndef DVD_H
#define DVD_H

#include <string>

// Klasa DVD reprezentujaca pojedynczy film w wypozyczalni
class DVD {
private:
    int id;
    std::string title;
    int year;
    std::string genre;
    std::string actor1;
    std::string actor2;
    bool available;

public:
    // Konstruktor
    DVD(int id, std::string title, int year, std::string genre, std::string actor1, std::string actor2);

    // Gettery
    int getId() const;
    std::string getTitle() const;
    int getYear() const;
    std::string getGenre() const;
    std::string getActor1() const;
    std::string getActor2() const;
    bool isAvailable() const;
    
    // Wyswietla pelne informacje o DVD
    void displayInfo() const;
    
    // Settery (editDVD.cpp)
    void setAvailable(bool status); 
    void setTitle(std::string newTitle);
    void setYear(int newYear);
    void setGenre(std::string newGenre);
    void setActors(std::string newActor1, std::string newActor2);
};

#endif