#ifndef CARSERVICE_OFFICEWORKER_H
#define CARSERVICE_OFFICEWORKER_H

#include "User.h"
#include "Warehouse.h"
#include "PriceList.h"
#include "Invoice.h"

class OfficeWorker {
public:
    OfficeWorker(const std::string& name);
    void manageWarehouse();
    void managePriceList();
    void issueInvoice();
private:
    User user;
    Warehouse warehouse;
    PriceList priceList;
};


#endif //CARSERVICE_OFFICEWORKER_H
