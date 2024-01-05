#include "Mechanic.h"
#include <iostream>

// Konstruktor klasy Mechanic inicjujący obiekt klasy User oraz kalendarz.
Mechanic::Mechanic(const std::string& name) : User(name) {}
Calendar calendar;

// Metoda zarządzająca magazynem, umożliwiająca wyświetlanie i edycję stanu.
void Mechanic::manageWarehouse() {
    Warehouse warehouse;
    warehouse.Wczytaj();

    std::cout << "STAN MAGAZYNU \n" << std::endl;

    std::cout << "1. Wyswietl stan magazynu\n";
    std::cout << "2. Edytuj istniejacy element\n";
    std::cout << "3. Wyjscie\n";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            warehouse.Wyswietl();
            std::cin.ignore();
            break;

        case 2:
            warehouse.Edytuj();
            break;
        case 3:
            return;
    }
}

// Metoda zarządzająca kalendarzem, umożliwiająca dodawanie, usuwanie i wyświetlanie napraw.
void Mechanic::manageCalendar() {
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
                // Zbieranie informacji od użytkownika systemu
                std::string type, reportDate, plannedDate, status;
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

                // Tworzenie obiektu klasy 'Event' i dodawanie go do wektora w klasie 'Calendar'
                Event event(type, reportDate, plannedDate, status);
                calendar.addEvent(event);

                std::cout << "Dodano wydarzenie do kalendarza.\n";
                break;
            }
            case 2: {
                int index;
                std::cout << "Podaj numer wydarzenia do usunięcia: ";
                std::cin >> index;
                calendar.removeEvent(index - 1);
                std::cout << "Usunięto wydarzenie z kalendarza.\n";
                break;
            }
            case 3:
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
