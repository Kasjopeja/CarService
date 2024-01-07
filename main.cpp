#include <iostream>

#include "User.h"
#include "OfficeWorker.h"
#include "Mechanic.h"

void officeWorkerMenu(std::string name)
{
    int choice = 0;

    while (choice != 4)
    {
        std::string role = "pracownik biura";
        OfficeWorker officeWorker(name, role);

        std::cout << "MENU GLOWNE:\n \n";

        std::cout << "1. Zarzadzaj magazynem\n";
        std::cout << "2. Zarzadzaj cennikiem\n";
        std::cout << "3. Wystaw fakture\n";
        std::cout << "4. Wyjscie\n";

        std::cin >> choice;

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

void mechanicMenu(std::string name)
{
    int choice = 0;

    while (choice != 3)
    {
        std::string role = "mechanik";
        Mechanic mechanic(name, role);

        std::cout << "MENU GLOWNE:\n \n";

        std::cout << "1. Zarzadzaj magazynem\n";
        std::cout << "2. Zarzadzaj kalendarzem\n";
        std::cout << "3. Wyjœcie\n";

        std::cin >> choice;

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
        }
    }
}


int main() {

    std::cout << "CAR SERVICE v0.1 \n " << std::endl;

    std::cout << "LOGOWANIE:\n";

    std::cout << "1. Pracownik Biura\n";
    std::cout << "2. Mechanik\n";

    int choice;
    std::cin >> choice;

    std::string name;
    std::cout << "\nPodaj imie: ";
    std::cin >> name;

    switch (choice)
    {
    case 1:
        officeWorkerMenu(name);
        break;
    case 2:
        mechanicMenu(name);
        break;
    }
}
