#include "PriceList.h"

void PriceList::addService() {
	std::cout << "Dodawanie nowej uslugi do cennika." << std::endl;
	unsigned int ID;
	std::string name;
	unsigned int price;
	std::cout << "Podaj ID: ";
	std::cin >> ID;

	std::cout << "Podaj nazwe: ";
	std::cin.ignore();			
	std::getline(std::cin, name);

	std::cout << "Podaj cene: ";
	std::cin >> price;	
	Service service(ID, name, price);
	services.push_back(service);
}

void PriceList::displayPriceList() {}

void PriceList::removeService(unsigned int ID) {}

//Service PriceList::WybierzUsluge(unsigned int ID) {}

void Service::changePrice(PriceList& priceList, unsigned int newPrice) {}

void Service::displayService() {}

Service::Service(unsigned int ID, std::string name, unsigned int price) : ID(ID), name(name), price(price) {}