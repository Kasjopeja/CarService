#include "OfficeWorker.h"
#include <iostream>

OfficeWorker::OfficeWorker(const std::string& name) : User(name) {}

void OfficeWorker::manageWarehouse() {
    
    while (true)
    {
        // wyswietlanie menu wyboru
        std::cout << "STAN MAGAZYNU " << std::endl;

        std::cout << "1. Wyswietl stan magazynu\n";
        std::cout << "2. Dodaj nowy element\n";
        std::cout << "3. Edytuj istniejacy element\n";
        std::cout << "4. Wyjscie\n";

        // zaladowanie informacji o stanie magazynu do programu
        Warehouse warehouse;
        warehouse.loadData();

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            // wysiwtlanie informacji o stanie magazynu
            warehouse.displayPart();
            std::cin.ignore();
            break;
        case 2:
            // dodawanie nowego elementu do magazynu - towrzenie obiektu klasy Part
            warehouse.addPart();
            break;
        case 3:
            // edytowanie informacji o stanie magazynu - konkretnym obieckie klasy Part 
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