#include "User.h"
#include <iostream>

User::User(const std::string& name, std::string& role) : name(name), role(role) {}


std::string User::getRole() const {
    return role;
}