#include "Event.h"

// Konstruktor klasy Event inicjujący dane dotyczące naprawy.
Event::Event(const std::string& type, const std::string& reportDate, const std::string& plannedDate, const std::string& status)
        : type(type), reportDate(reportDate), plannedDate(plannedDate), status(status) {}

// Metoda wyświetlająca informacje o konkretnym wydarzeniu (naprawie).
void Event::displayEvent() const {
    std::cout << "Usterka: " << type << std::endl;
    std::cout << "Data przyjęcia: " << reportDate << std::endl;
    std::cout << "Planowana data odbioru: " << plannedDate << std::endl;
    std::cout << "Aktualny status naprawy: " << status << std::endl;
}
