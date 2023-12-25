//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#include "User.h"
#include <iostream>

User::User(const std::string& name) : name(name) {}

void User::chooseRole() {
    std::cout << "Wybierz rolę (mechanik/pracownikBiura): ";
    std::cin >> role;
}

std::string User::getRole() const {
    return role;
}