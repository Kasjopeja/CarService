#ifndef CARSERVICE_MECHANIC_H
#define CARSERVICE_MECHANIC_H


#include "User.h"
#include "Warehouse.h"
#include "Calendar.h"

class Mechanic {
public:
    Mechanic(const std::string& name);
    void manageWarehouse();
    void manageCalendar();
private:
    User user;
    Warehouse warehouse;
    Calendar calendar;
};


#endif //CARSERVICE_MECHANIC_H
