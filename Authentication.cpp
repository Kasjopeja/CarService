#include "Authentication.h"
#include "includes.h"

bool Authentication::login(std::string login, std::string password) {
    if(login == "login" && password == "password") {
        cout << "Pomyslnie zalogowano." << endl;
        return true;
    }

    cout << "Bledne dane." << endl;
    return false;
}