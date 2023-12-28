#include "Mechanic.h"
#include <iostream>

Calendar calendar;

Mechanic::Mechanic(const std::string& name) : user(name) {}

void Mechanic::manageWarehouse() {
    std::cout << "Zarządzanie magazynem (stanem części)\n";
    // implementacja
}

void Mechanic::manageCalendar() {
    int choice;
    do {
        std::cout << "Wybierz akcję edycji kalendarza:\n";
        std::cout << "1. Dodaj usterkę\n";
        std::cout << "2. Usuń usterkę\n";
        std::cout << "3. Wyświetl kalendarz\n";
        std::cout << "0. Wyjście\n";
        std::cout << "Wybór: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Dodawanie wydarzenia
                std::string type, reportDate, plannedDate;
                std::cin.ignore();
                std::cout << "Podaj typ usterki: ";
                std::getline(std::cin, type);
                std::cout << "Podaj datę zgłoszenia (dd-mm-rrrr): ";
                std::cin >> reportDate;
                std::cout << "Podaj planowaną datę wykonania (dd-mm-rrrr): ";
                std::cin >> plannedDate;

                Event event(type, reportDate, plannedDate);
                calendar.addEvent(event);

                std::cout << "Dodano wydarzenie do kalendarza.\n";
                break;
            }
            case 2: {
                // Usuwanie wydarzenia
                int index;
                std::cout << "Podaj numer wydarzenia do usunięcia: ";
                std::cin >> index;
                calendar.removeEvent(index - 1); // -1, bo numerowanie od 1 dla użytkownika
                std::cout << "Usunięto wydarzenie z kalendarza.\n";
                break;
            }
            case 3:
                // Wyświetlanie wydarzeń
                calendar.displayEvents();
                break;
            case 0:
                std::cout << "Koniec edycji kalendarza.\n\n";
                break;
            default:
                std::cout << "Nieprawidłowy wybór.\n";
                break;
        }
    } while (choice != 0);
}