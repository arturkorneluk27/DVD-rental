#include <iostream>
// transform()
#include <algorithm>
#include <cctype>
#include "search.h"
#include "utils.h"
using namespace std;

// Zamienia string na male litery
string toLower(string str) {
    // str.begin(), str.end() - cały string (kazdy znak)   /  wynik transform zapisywany do iteratora = str.begin()
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return tolower(c); });
    return str;
}

// Sprawdza czy string (text) zawiera podciag (search)
bool contains(string text, string search) {
    return toLower(text).find(toLower(search)) != string::npos;
}


//=================================================================================


void searchByTitle(const vector<DVD> &movies) {
    string searchTitle;

    cout<<"\n==== WYSZUKIWANIE PO TYTULE ===="<<endl;
    cout<<"Wpisz tytul: ";
    getline(cin, searchTitle);
    
    if(searchTitle.empty()) {
        cout<<"\nTo pole nie moze byc puste!"<<endl;
        return;
    }

    cout<<"\n==== WYNIKI WYSZUKIWANIA ===="<<endl;

    bool found = false;
    for(const DVD &m :movies) {
        // Przeszukuje wszystkie filmy, poszukujac podciągów
        if(contains(m.getTitle(), searchTitle)) {
            m.displayInfo();
            found = true;
        }
    }

    if(!found) {
        cout<<"\n Nie znaleziono filmu z takim tytulem." <<endl;
    }

    pause();
}


//========================================================================


void searchByGenre(const vector<DVD> &movies) {
    string searchGenre;

    cout<<"\n==== WYSZUKIWANIE PO GATUNKU ===="<<endl;
    cout<<"Wpisz gatunek: ";
    getline(cin, searchGenre);
    
    if(searchGenre.empty()) {
        cout<<"\nTo pole nie moze byc puste!"<<endl;
        return;
    }

    cout<<"\n==== WYNIKI WYSZUKIWANIA ===="<<endl;

    bool found = false;
    for(const DVD &m :movies) {
        // Przeszukuje wszystkie filmy, poszukujac podciągów
        if(contains(m.getGenre(), searchGenre)) {
            m.displayInfo();
            // Znalezlismy
            found = true;
        }
    }

    if(!found) {
        cout<<"\n Nie znaleziono filmu takiego gatunku." <<endl;
    }

    pause();
}


//================================================================


void searchByActor(const vector<DVD> &movies) {
    string searchActor;

    cout<<"\n==== WYSZUKIWANIE PO AKTORZE ===="<<endl;
    cout<<"Wpisz imie lub nazwisko aktora: ";
    getline(cin, searchActor);
    
    if(searchActor.empty()) {
        cout<<"\nTo pole nie moze byc puste!"<<endl;
        return;
    }

    cout<<"\n==== WYNIKI WYSZUKIWANIA ===="<<endl;

    bool found = false;
    for(const DVD &m :movies) {
        // Przeszukuje wszystkie filmy, poszukujac podciągów
        if(contains(m.getActor1(), searchActor) || contains(m.getActor2(), searchActor) ) {
            m.displayInfo();
            found = true;
        }
    }

    if(!found) {
        cout<<"\n Nie znaleziono filmu z takim aktorem." <<endl;
    }

    pause();
}

