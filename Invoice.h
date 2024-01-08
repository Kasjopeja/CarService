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
    
    float charge; //należność jako float
    std::vector<Event> events;  // zlecenie w vectorze

public:

    
    void addPartsData(const Part& part);  //dodawanie czesci do faktury
   

    void addEventData(const Event& event);  //dodawanie zlecenie do faktury
    void addClient();   //dodaje dane klienta
    void Print(const std::string& fileName);   //drukowanie faktury
};


#endif //CARSERVICE_INVOICE_H
