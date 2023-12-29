
#ifndef CARSERVICE_PRICELIST_H
#define CARSERVICE_PRICELIST_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class PriceList;

class Service {
	std::string name;
	unsigned int price;
	unsigned int ID;
	friend class PriceList;		
public:
	Service(unsigned int, std::string, unsigned int);
	void displayService();
	void changePrice(PriceList& priceList, unsigned int newPrice);
};

class PriceList {
	std::vector<Service> services;
public:
	void displayPriceList();
	void addService();
	void removeService(unsigned int ID);
	Service chooseService(unsigned int ID);

};


#endif //CARSERVICE_PRICELIST_H
