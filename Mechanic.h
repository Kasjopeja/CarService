#ifndef CARSERVICE_MECHANIC_H
#define CARSERVICE_MECHANIC_H

#include "User.h"
#include "Warehouse.h"
#include "Calendar.h"

// Klasa reprezentująca mechanika odpowiedzialnego za zarządzanie magazynem i kalendarzem napraw.
class Mechanic : public User {
public:
    // Konstruktor klasy Mechanic inicjujący obiekt klasy User oraz kalendarz.
    Mechanic(const std::string& name, std::string& role);

    // Metoda zarządzająca magazynem, umożliwiająca wyświetlanie i edycję stanu.
    void manageWarehouse();

    // Metoda zarządzająca kalendarzem, umożliwiająca dodawanie, usuwanie i wyświetlanie napraw.
    void manageCalendar();

private:
    Warehouse warehouse;    // Obiekt klasy Warehouse reprezentujący magazyn.
    Calendar calendar;      // Obiekt klasy Calendar reprezentujący kalendarz napraw.
};

#endif //CARSERVICE_MECHANIC_H
