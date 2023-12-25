#include <iostream>
#include "User.h"
#include "OfficeWorker.h"
#include "Mechanic.h"

int main() {
    std::string name;
    std::cout << "Podaj imię: ";
    std::cin >> name;

    User user(name);
    user.chooseRole();

    if (user.getRole() == "pracownikBiura") {
        OfficeWorker officeWorker(name);
        int choice;
        do {
            std::cout << "Wybierz akcję:\n";
            std::cout << "1. Zarządzaj magazynem\n";
            std::cout << "2. Zarządzaj cennikiem\n";
            std::cout << "3. Wystaw fakturę\n";
            std::cout << "0. Wyjście\n";
            std::cout << "Wybór: ";
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
                case 0:
                    std::cout << "Koniec programu.\n";
                    break;
                default:
                    std::cout << "Nieprawidłowy wybór.\n";
                    break;
            }
        } while (choice != 0);
    } else if (user.getRole() == "mechanik") {
        Mechanic mechanic(name);
        int choice;
        do {
            std::cout << "Wybierz akcję:\n";
            std::cout << "1. Zarządzaj magazynem\n";
            std::cout << "2. Zarządzaj kalendarzem\n";
            std::cout << "0. Wyjście\n";
            std::cout << "Wybór: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    mechanic.manageWarehouse();
                    break;
                case 2:
                    mechanic.manageCalendar();
                    break;
                case 0:
                    std::cout << "Koniec programu.\n";
                    break;
                default:
                    std::cout << "Nieprawidłowy wybór.\n";
                    break;
            }
        } while (choice != 0);
    } else {
        std::cout << "Nieprawidłowa rola.\n";
    }

    return 0;
}
