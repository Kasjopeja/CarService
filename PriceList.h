
#ifndef CARSERVICE_PRICELIST_H
#define CARSERVICE_PRICELIST_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class PriceList;

class Service {
	std::string name;
	unsigned int price;
	unsigned int ID;
	friend class PriceList;		
public:
	Service(unsigned int, std::string, unsigned int);
	void Wyswietl();
	void ZmienCene(PriceList& cennik, unsigned int nowaCena);
};

class PriceList {
	std::vector<Service> services;
public:
	void WyswietlCennik();
	void addService();
	void UsunUsluge(unsigned int ID);
	Service WybierzUsluge(unsigned int ID);

};


#endif //CARSERVICE_PRICELIST_H
