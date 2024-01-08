#ifndef CARSERVICE_INVOICE_H
#define CARSERVICE_INVOICE_H


#include "Event.h"
#include "Warehouse.h"
#include <vector>

class Client {
    std::string name;
    std::string lastname;
    std::string mailAdress;
    std::string phoneNumber;

public:
    Client(std::string, std::string, std::string, std::string);
};

class Invoice {
    std::vector<Event> events;  // zlecenie w vectorze

public:

    
    void addPartsData(const Part& part);  //dodawanie czesci do faktury
    void addEventData();  //dodawanie zlecenie do faktury
    void addClient();   //dodaje dane klienta
    void addCharge();   //dodawanie kosztu do faktury
};


#endif //CARSERVICE_INVOICE_H
