
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
	std::vector<Service> services;
public:
	void WyswietlCennik();
	void DodajUsluge(Service& usluga);
	void UsunUsluge(unsigned int ID);
	Service WybierzUsluge(unsigned int ID);

};


#endif //CARSERVICE_PRICELIST_H
