#include "main.h"
#include "MainMenu.h"
#include "Authentication.h"
#include "includes.h"

int main()
{

MainMenu::initial();

bool isLoggedIn = Authentication::login(MainMenu::getLogin(), MainMenu::getPassword());

while (isLoggedIn) {
    MainMenu::chooseAction();
}

}