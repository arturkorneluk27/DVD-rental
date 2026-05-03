#include <iostream>
#include <conio.h>    // funkcja getch()
#include <limits>
#include "utils.h"
using namespace std;


void pause() {
    cout << "\nNacisnij dowolny klawisz, aby kontynuowac..."<<endl;
    (void)getch();
}


//========================================================================


int getInt() {
    int value;
   
    while(true) {
        if(cin >> value) {
            // Czysci pozostale znaki z bufora
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        // NIepoprawne dane
        cout<<"\nBledne dane! Podaj liczbe: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}