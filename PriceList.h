#ifndef CARSERVICE_PRICELIST_H
#define CARSERVICE_PRICELIST_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class PriceList;

class Service {
	std::string name;		//nazwa uslugi
	unsigned int price;		//cena uslugi
	unsigned int ID;		//ID uslugi
			
public:
	Service(unsigned int, std::string, unsigned int);		//konstruktor
	void displayService();									//wyswietla pojedyncza usluge
	void changePrice(unsigned int newPrice);				//zmienia cene uslugi
	unsigned int getIdService() const;	
	std::string getName() const;
	unsigned int getPrice() const;
};

class PriceList {
	std::vector<Service> services;			//wektor przechowujacy uslugi
	unsigned int selectedID = 0;			//zmienna do przechowywania ID wybranej uslugi
public:
	void displayPriceList();				//wyswietlanie cennika
	void addService();						//dodawanie nowej uslugi do cennika
	void removeService(unsigned int ID);	//usuwanie uslugi z cennika
	void chooseService();					//wybieranie uslugi
	void addService(const Service& usluga);	
	void changePrice();						//zmiana ceny uslugi
};


#endif //CARSERVICE_PRICELIST_H
