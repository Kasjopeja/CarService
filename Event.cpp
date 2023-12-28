#include "Event.h"

Event::Event(const std::string& type, const std::string& reportDate, const std::string& plannedDate)
        : type(type), reportDate(reportDate), plannedDate(plannedDate) {}

void Event::displayEvent() const {
    std::cout << "Usterka: " << type << "\n";
    std::cout << "Data przyjęcia: " << reportDate << "\n";
    std::cout << "Planowana data odbioru: " << plannedDate << "\n";
}