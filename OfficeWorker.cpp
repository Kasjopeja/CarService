#include "OfficeWorker.h"
#include <iostream>

OfficeWorker::OfficeWorker(const std::string& name) : User(name) {}

void OfficeWorker::manageWarehouse() {
    
    while (true)
    {
        //system("cls");

        std::cout << "STAN MAGAZYNU " << std::endl;

        std::cout << "1. Wyswietl stan magazynu\n";
        std::cout << "2. Dodaj nowy element\n";
        std::cout << "3. Edytuj istniejacy element\n";
        std::cout << "4. Wyjscie\n";

        Warehouse warehouse;
        warehouse.loadData();

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:

            warehouse.displayPart();
            std::cin.ignore();
            break;
        case 2:
            warehouse.addPart();
            break;
        case 3:
            warehouse.editPart();
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