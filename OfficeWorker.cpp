#include "OfficeWorker.h"
#include "Invoice.h"
#include "Event.h"
#include "Warehouse.h"
#include <iostream>

OfficeWorker::OfficeWorker(const std::string& name, std::string& role) : User(name, role) {}

void OfficeWorker::manageWarehouse() {
    
    while (true)
    {
        // wyswietlanie menu wyboru
        std::cout << "STAN MAGAZYNU " << std::endl;

        std::cout << "0. Wyswietl stan zamowien\n";
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
        case 0:
            // wysiwtlanie informacji o stanie zamowien
            warehouse.displayOrders();
            std::cin.ignore();
            break;
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
    while (true)
    {
        //system("cls");

        std::cout << "WYSTAWIANIE FAKTURY " << std::endl;

        std::cout << "1. Dodanie klienta do faktury" << std::endl;
        std::cout << "2. Dodaj zlecenia do faktury" << std::endl;
        std::cout << "3. Dodanie części do faktury" << std::endl;
        std::cout << "4. Wyjscie" << std::endl;

        Invoice invoice;

        int choice;
        std::cin >> choice;
        Part part(1, "Nakladka", 10);
        Event event("Wyciek", "2024-01-04", "2024-01-10", "Zakonczone");

        switch (choice)
        {
        case 1:

            invoice.addClient();
            std::cin.ignore();
            break;
        case 2:
          //  invoice.addEventData(event);
            break;
        case 3:
            invoice.addPartsData(part);
            break;

        case 4:
            return;
        }
    }
    // implementacja
}