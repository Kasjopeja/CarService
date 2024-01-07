#ifndef CARSERVICE_EVENT_H
#define CARSERVICE_EVENT_H

#include <string>
#include <iostream>

// Klasa reprezentująca pojedyncze wydarzenie - naprawę samochodu.
class Event {
public:
    // Konstruktor klasy Event inicjujący dane dotyczące naprawy.
    Event(const std::string& type, const std::string& reportDate, const std::string& plannedDate, const std::string& status);

    // Metoda wyświetlająca informacje o konkretnym wydarzeniu (naprawie).
    void displayEvent() const;

private:
    std::string type;           // Typ usterki.
    std::string reportDate;     // Data zgłoszenia.
    std::string plannedDate;    // Planowana data wykonania.
    std::string status;         // Aktualny status naprawy.
};

#endif //CARSERVICE_EVENT_H
