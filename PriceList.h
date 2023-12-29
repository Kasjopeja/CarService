//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#ifndef CARSERVICE_PRICELIST_H
#define CARSERVICE_PRICELIST_H

#include <iostream>
#include <vector>
#include <string>

class PriceList;

class Service {
    std::string name;
    unsigned int price;
    unsigned int ID;
    public:
        Service(std::string, unsigned int, unsigned int);
        void Wyswietl();
        void ZmienCene(PriceList& cennik, unsigned int nowaCena);
};

class PriceList {
public:
    // funkcje związane z cennikiem
};


#endif //CARSERVICE_PRICELIST_H
