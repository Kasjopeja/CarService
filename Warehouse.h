//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#ifndef CARSERVICE_WAREHOUSE_H
#define CARSERVICE_WAREHOUSE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
#include <string>


class Warehouse {
public:

    std::vector <Parts> Wczytaj();
};

class Parts
{
    unsigned int ID;
    std::string name;
    unsigned int amount;

public:

    Parts(unsigned int, std::string, unsigned int);
};


#endif //CARSERVICE_WAREHOUSE_H
