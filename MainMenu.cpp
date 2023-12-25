#include "MainMenu.h"
#include "includes.h"
#include "Authentication.h"

void MainMenu::initial() {
    cout << "Witamy w systemie, konieczne jest logowanie." << endl;
}

string MainMenu::getLogin() {
    string login;
    cout << "Podaj login: ";
    cin >> login;
    return login;
}

string MainMenu::getPassword() {
    string login;
    cout << "Podaj haslo: ";
    cin >> login;
    return login;
}

void MainMenu::chooseAction() {
    int num;
    cout << "--- Wybierz dzialanie z listy poniżej ---" << endl;
    cout << "1. Operacja 1" << endl;
    cout << "2. Operacja 1" << endl;
    cout << "3. Operacja 1" << endl;
    cout << "4. Operacja 1" << endl;
    cout << "5. Operacja 1" << endl;
    cout << "6. Operacja 1" << endl;
    cout << "Podaj numer operacji: ";
    cin >> num;

    switch (num) {
        case 1:
            // wywolanie odpowiedniej funkcji
            break;
        case 2:
            // wywolanie odpowiedniej funkcji
            break;
        case 3:
            // wywolanie odpowiedniej funkcji
            break;
        case 4:
            // wywolanie odpowiedniej funkcji
            break;
        case 5:
            // wywolanie odpowiedniej funkcji
            break;
        case 6:
            // wywolanie odpowiedniej funkcji
            break;
    }
}


