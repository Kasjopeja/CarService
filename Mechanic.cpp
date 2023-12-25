//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#include "Mechanic.h"
#include <iostream>

Mechanic::Mechanic(const std::string& name) : user(name) {}

void Mechanic::manageWarehouse() {
    std::cout << "Zarządzanie magazynem (stanem części)\n";
    // implementacja
}

void Mechanic::manageCalendar() {
    std::cout << "Zarządzanie kalendarzem\n";
    // implementacja
}