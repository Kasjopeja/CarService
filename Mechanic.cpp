#include "Mechanic.h"
#include <iostream>

Mechanic::Mechanic(const std::string& name) : User(name) {}
Calendar calendar;

void Mechanic::manageWarehouse() {

    Warehouse warehouse;
    warehouse.loadData();

    std::cout << "STAN MAGAZYNU \n" << std::endl;

    std::cout << "1. Wyswietl stan magazynu\n";
    std::cout << "2. Edytuj istniejacy element\n";
    std::cout << "3. Wyjscie\n";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        warehouse.displayPart();
        std::cin.ignore();
        break;

    case 2:
        warehouse.editPart();
        break;
    case 3:
        return;
    }
}

void Mechanic::manageCalendar() {

    // proste menu
    int choice;
    do {

        std::cout << "EDYCJA KALENDARZA\n";
        std::cout << "1. Dodaj usterke\n";
        std::cout << "2. Usun usterke\n";
        std::cout << "3. Wyswietl kalendarz\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Dodawanie wydarzenia
            std::string type, reportDate, plannedDate, status;  // inicjowanie zmiennych
            std::cin.ignore();
            std::cout << "Podaj typ usterki: ";
            std::getline(std::cin, type);
            std::cout << "Podaj datę zgłoszenia (dd-mm-rrrr): ";
            std::cin >> reportDate;
            std::cout << "Podaj planowaną datę wykonania (dd-mm-rrrr): ";
            std::cin >> plannedDate;
            std::cin.ignore();
            std::cout << "Podaj aktualny status naprawy: ";
            std::getline(std::cin, status);

            // użycie konstruktora i wywołanie metody, która dodaje obiekt do vectora w kalendarzu
            Event event(type, reportDate, plannedDate, status);
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