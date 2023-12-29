#include "PriceList.h"

unsigned int Service::getIdService() const {
	return ID;
}
std::string Service::getName() const {
	return name;
}
unsigned int Service::getPrice() const {
	return price;
}

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

void PriceList::displayPriceList() {
	std::cout << "Cennik uslug:" << std::endl;
	for (Service& usluga : services) {
		usluga.displayService();
	}
}


void PriceList::removeService(unsigned int ID) {
	auto it = std::remove_if(services.begin(), services.end(),
		[ID](const Service& usluga) { return usluga.getIdService() == ID; });

	if (it != services.end()) {
		services.erase(it, services.end());
		std::cout << "Usluga o ID " << ID << " zostala usunieta z cennika." << std::endl;
	}
	else {
		std::cout << "Nie znaleziono uslugi o ID " << ID << " w cenniku." << std::endl;
	}
}

void PriceList::addService(const Service& usluga) {
	services.push_back(usluga);
}
//Service PriceList::chooseService(unsigned int ID) {}

void Service::changePrice(unsigned int price) {
	this->price = price;
}

void PriceList::changePrice(unsigned int ID) {
	for (Service& usluga : services) {
		if (usluga.getIdService() == ID) {
			unsigned int newPrice;
			std::cout << "Wprowadz nowa cene dla uslugi o ID " << ID << ": ";
			std::cin >> newPrice;

			if (std::cin.fail()) {
				std::cerr << "Blad: Nieprawidlowe dane wejsciowe." << std::endl;
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
				return;
			}

			usluga.changePrice(newPrice);
			std::cout << "Zmieniono cene uslugi o ID " << ID << " na " << newPrice << std::endl;
			return;
		}
	}
	std::cout << "Nie znaleziono uslugi o ID " << ID << std::endl;
}

void Service::displayService() {
	std::cout << "ID: " << ID << " Nazwa: " << name << " Cena: " << price << std::endl;
}

Service::Service(unsigned int ID, std::string name, unsigned int price) : ID(ID), name(name), price(price) {}