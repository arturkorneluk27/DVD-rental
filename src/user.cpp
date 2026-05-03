#include "user.h"
#include <iostream>
using namespace std;

User::User(string login, string password) : login(login), password(password) {}

bool User::verification(string l, string p) const {
    return login==l && password==p;
}

string User::getLogin() const {
    return login;
}

string User::getPassword() const {
    return password;
}