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
#include <sstream>

class Parts
{
    unsigned int ID;
    std::string name;
    unsigned int amount;

public:

    Parts(unsigned int, std::string, unsigned int);
    void Wyswietl();
    void Edytuj();
};


class Warehouse {

    std::vector <Parts> stanMagazynu;

public:

    void Wczytaj();
    void Wyswietl();
    void Edytuj();
    void Dodaj();
};



#endif //CARSERVICE_WAREHOUSE_H
