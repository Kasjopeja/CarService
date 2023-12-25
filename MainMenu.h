#ifndef CARSERVICE_MAINMENU_H
#define CARSERVICE_MAINMENU_H

#include "includes.h"

class MainMenu {
public:
    static void initial();
    static void chooseAction();

    static string getLogin();
    static string getPassword();
private:
    bool isLoggedIn;
};


#endif //CARSERVICE_MAINMENU_H
