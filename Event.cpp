//
// Created by Jakub Wawrzyczek on 28/12/2023.
//

#include "Event.h"

Event::Event(const std::string& type, const std::string& reportDate, const std::string& plannedDate)
        : type(type), reportDate(reportDate), plannedDate(plannedDate) {}

void Event::displayEvent() const {
    std::cout << "Type: " << type << "\n";
    std::cout << "Report Date: " << reportDate << "\n";
    std::cout << "Planned Date: " << plannedDate << "\n";
}