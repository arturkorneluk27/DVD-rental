#include "admin.h"
#include <iostream>
using namespace std;

Admin::Admin(string login, string password) : User(login, password) {}


void Admin::displayInfo() const {
    cout<<"Login: "<< login <<endl;
    cout<<"Password: "<< password <<endl;
}


bool Admin::loginAdmin() {
    string login, password;
    cout<<"==== LOGOWANIE ADMINISTRATORA ===="<<endl;
    cout<<"Login: ";
    cin>>login;
    cout<<"Password: ";
    cin>>password;

    // Weryfikacja
    if(verification(login, password)) {
        cout<<"\nZalogowano jako administrator!"<<endl;
        return true;
    }
    cout<<"\nBledny login lub haslo administratora!"<<endl;
    return false;
}

