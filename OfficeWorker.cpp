//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#include "OfficeWorker.h"
#include <iostream>

OfficeWorker::OfficeWorker(const std::string& name) : User(name) {}

void OfficeWorker::manageWarehouse() {
    
    while (true)
    {
        system("cls");

        std::cout << "STAN MAGAZYNU \n\n" << std::endl;

        Warehouse warehouse;
        warehouse.Wczytaj();
        warehouse.Wyswietl();

        std::cout << "\n \nPodaj ID elementu ktorego szczegoly chcesz edytowac, wpisz \"exit\" by wyjsc" << std::endl;
        std::string action;
        std::cin >> action;

        if (action == "exit") { return; }
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