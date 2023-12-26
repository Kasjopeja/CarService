#ifndef CARSERVICE_MENU_H
#define CARSERVICE_MENU_H


class Menu {

    int selectedOption;

public:

    Menu(void);
    int showAllOpions(int);
    bool navigate(int);
    int getSelectedOption();
  
};


#endif //CARSERVICE_INVOICE_H