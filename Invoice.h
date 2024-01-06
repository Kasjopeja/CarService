#ifndef CARSERVICE_INVOICE_H
#define CARSERVICE_INVOICE_H


#include "Event.h"
#include "Warehouse.h"
#include "Invoice.cpp"

class Invoice {
    
    float charge; //należność jako float

public:


    void addEvent(const Event& event);  //dodawanie zlecenie do faktury
    void addParts(Parts& parts);    //dodawanie czesci do faktury
    void addClient(const Client& client, std::ofstream& invoiceFile);   //dodaje dane klienta
    void Print();   //drukowanie faktury
};



#endif //CARSERVICE_INVOICE_H
