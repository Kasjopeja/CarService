#include "OfficeWorker.h"
#include <iostream>
#include "Menu.h"

OfficeWorker::OfficeWorker(const std::string& name) : User(name) {}

void OfficeWorker::manageWarehouse() {
    
    while (true)
    {
        system("cls");

        std::cout << "STAN MAGAZYNU " << std::endl;

        Warehouse warehouse;
        warehouse.Wczytaj();

        Menu menuStanMagazynu;
        char key;
        int maxOption;
        int choice;
        std::string ID;

        do {
            maxOption = menuStanMagazynu.showAllOpions(3);
            key = menuStanMagazynu.navigate(maxOption);

        } while (!key);

        system("cls");
        choice = menuStanMagazynu.getSelectedOption();

        switch (choice)
        {
        case 1:
            warehouse.Wyswietl();
            std::cin >> ID;
            break;
        case 2:
            warehouse.Dodaj();
            break;
        case 3:
            warehouse.Edytuj();
            break;

        case 4:
            return;
        }
    }

}

void OfficeWorker::managePriceList() {
    std::cout << "Zarządzanie cennikiem\n";
    // implementacja
}

void OfficeWorker::issueInvoice() {
    std::cout << "Wystawianie faktury\n";
    // implementacja
}