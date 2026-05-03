#include "search_menu.h"
#include <iostream>
#include "utils.h"
using namespace std;

void searchDVD(const vector<DVD> &movies) {
    int choice;

    // Glowna petla menu wyszukiwania
    while(true) {
        cout<<"\n===== WYSZUKIWANIE FILMOW ====="<<endl;
        cout<<"1. Szukaj po tytule"<<endl;
        cout<<"2. Szukaj po gatunku"<<endl;
        cout<<"3. Szukaj po aktorze"<<endl;
        cout<<"4. Powrot"<<endl;
        cout<<"==============================="<<endl;
        cout<<"Wybierz opcje: ";
        choice = getInt();

        switch(choice) {
            case 1:
                // Wyszukiwanie po tytule
                searchByTitle(movies);
                break;
            case 2:
                // Wyszukiwanie po gatunku
                searchByGenre(movies);
                break;
            case 3:
                // Wyszukiwanie po aktorze
                searchByActor(movies);
                break;
            case 4:
                // Powrot do menu glownego
                return;
            default:
                cout<<"Niepoprawny wybor."<<endl;
        }

    }
}