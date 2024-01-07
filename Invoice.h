#ifndef CARSERVICE_INVOICE_H
#define CARSERVICE_INVOICE_H


#include "Event.h"
#include "Warehouse.h"
#include "Invoice.cpp"
#include <vector>

class Invoice {
    
    float charge; //należność jako float
    std::vector<Event> events;  // zlecenie w vectorze

public:
    std::vector<Event> getEvents() const;   // getter do wyciągania zleceń

    void addEvent(const Event& event);  //dodawanie zlecenie do faktury
    void addParts(Parts& parts);    //dodawanie czesci do faktury
    void addClient(const Client& client, std::ofstream& invoiceFile);   //dodaje dane klienta
    void Print(const std::string& fileName);   //drukowanie faktury
};



#endif //CARSERVICE_INVOICE_H
