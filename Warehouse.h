#ifndef CARSERVICE_WAREHOUSE_H
#define CARSERVICE_WAREHOUSE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class Part
{
    unsigned int ID;
    std::string name;
    unsigned int amount;

public:

    Part(unsigned int, std::string, unsigned int);
    void displayPart();
    void editPart(unsigned int);
    void saveChangesToFIle();
};


class Warehouse {

    std::vector <Part> warehouseState;
    std::vector <Part> orderState;

public:

    void loadData();
    void displayPart();
    void editPart();
    void addPart();
    void addOrder();
    void displayOrders();

};



#endif //CARSERVICE_WAREHOUSE_H
