//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#include "Mechanic.h"
#include "Menu.h"
#include <iostream>

Mechanic::Mechanic(const std::string& name) : User(name) {}

void Mechanic::manageWarehouse() {

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
        break;
    case 3:
        break;
    case 4:
        return;
    }
}

void Mechanic::manageCalendar() {
    std::cout << "Zarządzanie kalendarzem\n";
    // implementacja
}