#include <iostream>

#include "User.h"
#include "OfficeWorker.h"
#include "Mechanic.h"
#include "Menu.h"

enum interface
{
    menuLogowanie = 0,
    menuForPracownikBiura = 1,
    menuForMechanik = 2
};

int main() {

    Menu mainMenuLogowanie;
    char key;
    int maxOption;
    int choice;

    do {
        maxOption = mainMenuLogowanie.showAllOpions(menuLogowanie);
        key = mainMenuLogowanie.navigate(maxOption);

    } while (!key);

      std::string name;
      std::cout << "\nPodaj imie: ";
      std::cin >> name;


    choice = mainMenuLogowanie.getSelectedOption();

    if (choice == 1) {

        while (choice != 4)
        {
            OfficeWorker officeWorker(name);
            Menu mainMenuPracownikBiura;

            do {
                maxOption = mainMenuPracownikBiura.showAllOpions(menuForPracownikBiura);
                key = mainMenuPracownikBiura.navigate(maxOption);

            } while (!key);

            choice = mainMenuPracownikBiura.getSelectedOption();

            switch (choice) {
            case 1:
                officeWorker.manageWarehouse();
                break;
            case 2:
                officeWorker.managePriceList();
                break;
            case 3:
                officeWorker.issueInvoice();
                break;
            case 4:
                std::cout << "Koniec programu.\n";
                break;
            }


        }
    }
    
    if (choice == 2) {
        
        while (choice != 3)
        {
            Mechanic mechanic(name);
            Menu mainMenuMechanic;

            do {
                maxOption = mainMenuMechanic.showAllOpions(menuForMechanik);
                key = mainMenuMechanic.navigate(maxOption);

            } while (!key);

            choice = mainMenuMechanic.getSelectedOption();

            switch (choice) {
            case 1:
                mechanic.manageWarehouse();
                break;
            case 2:
                mechanic.manageCalendar();
                break;
            case 3:
                std::cout << "Koniec programu.\n";
                break;

                return 0;
            }
        }
    }
}
