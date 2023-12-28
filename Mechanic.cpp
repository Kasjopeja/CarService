#include "Mechanic.h"
#include "Menu.h"
#include <iostream>

Mechanic::Mechanic(const std::string& name) : User(name) {}
Calendar calendar;

void Mechanic::manageWarehouse() {

    system("cls");

    std::cout << "STAN MAGAZYNU " << std::endl;

    Warehouse warehouse;
    warehouse.Wczytaj();

    Menu menuStanMagazynu;
    char key;
    int maxOption;
    int choice;
    std::string ID;

    do {
        maxOption = menuStanMagazynu.showAllOpions(4);
        key = menuStanMagazynu.navigate(maxOption);

    } while (!key);

    system("cls");
    choice = menuStanMagazynu.getSelectedOption();

    switch (choice)
    {
    case 1:
        warehouse.Wyswietl();
        std::cin >> ID;
        break;

    case 2:
        warehouse.Edytuj();
        break;
    case 3:
        return;
    }
}

void Mechanic::manageCalendar() {

    int choice;
    do {

        std::cout << "Wybierz akcje edycji kalendarza:\n";
        std::cout << "1. Dodaj usterke\n";
        std::cout << "2. Usun usterke\n";
        std::cout << "3. Wyswietl kalendarz\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybor: ";
        std::cin >> choice;
        system("cls");

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