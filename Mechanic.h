#ifndef CARSERVICE_MECHANIC_H
#define CARSERVICE_MECHANIC_H


#include "User.h"
#include "Warehouse.h"
#include "Calendar.h"

class Mechanic : public User {
public:
    Mechanic(const std::string& name);  // konstruktor obiektu klasy mechanik
    void manageWarehouse();
    void manageCalendar();  // metoda zarz¹dzaj¹ca kalendarzem
private:
    Warehouse warehouse;
    Calendar calendar;  // tworzenie obiektu klasy calendar dla ka¿dego mechanika z osobna
};


#endif //CARSERVICE_MECHANIC_H