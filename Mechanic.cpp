//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#include "Mechanic.h"
#include <iostream>

Mechanic::Mechanic(const std::string& name) : User(name) {}

void Mechanic::manageWarehouse() {
    
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

void Mechanic::manageCalendar() {
    std::cout << "Zarządzanie kalendarzem\n";
    // implementacja
}