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
	Service usluga(ID, name, price);
	services.push_back(usluga);
}

void PriceList::WyswietlCennik() {}

void PriceList::UsunUsluge(unsigned int ID) {}

//Service PriceList::WybierzUsluge(unsigned int ID) {}

void Service::ZmienCene(PriceList& cennik, unsigned int nowaCena) {}

void Service::Wyswietl() {}

Service::Service(unsigned int ID, std::string name, unsigned int price) : ID(ID), name(name), price(price) {}