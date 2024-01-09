#include "PriceList.h"

//zwracanie ID uslugi, nazwy i ceny
unsigned int Service::getIdService() const {
	return ID;
}
std::string Service::getName() const {
	return name;
}
unsigned int Service::getPrice() const {
	return price;
}

//dodawanie nowej uslugi do cennika
void PriceList::addService() {
	std::cout << "Dodawanie nowej uslugi do cennika." << std::endl;

	//deklaracja zmiennych
	unsigned int ID;
	std::string name;
	unsigned int price;

	//pobieranie ID od uzytkownika
	std::cout << "Podaj ID: ";
	std::cin >> ID;

	//sprawdzanie czy usluga o podanym ID juz istnieje
	auto it = std::find_if(services.begin(), services.end(),
		[ID](const Service& service) {
			return service.getIdService() == ID;
		});

	if (it != services.end()) {
		//przerwanie dodawania uslugi jesli usluga o podanym ID juz istnieje
		std::cout << "Usluga o ID " << ID << " istnieje juz w cenniku." << std::endl;
		return;
	}

	//pobieranie nazwy od uzytkownika
	std::cout << "Podaj nazwe: ";
	std::cin.ignore();				
	std::getline(std::cin, name);

	//pobieranie ceny od uzytkownika
	std::cout << "Podaj cene: ";
	std::cin >> price;

	//tworzenie nowego obiektu uslugi i dodawanie go do listy us³ug
	Service service(ID, name, price);
	services.push_back(service);
}

//wyswietlanie cennika
void PriceList::displayPriceList() {
	std::cout << "Cennik uslug:" << std::endl;
	for (Service& usluga : services) {
		usluga.displayService();		//wyswietlanie uslugi
	}
}

//usuwanie uslugi z cennika
void PriceList::removeService(unsigned int ID) {

	//szukanie uslugi o podanym ID, przenoszenie jej na koniec i usuwanie
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
//dodawanie istniejacej uslugi do cennika
void PriceList::addService(const Service& service) {
	services.push_back(service);
}

//aktualizacja ceny uslugi
void Service::changePrice(unsigned int price) {
	this->price = price;
}

//zmiana ceny uslugi
void PriceList::changePrice() {
	unsigned int ID = selectedID;	//przypisanie zmiennej ID wybranej uslugi

	//szukanie uslugi o podanym ID 
	for (Service& service : services) {
		if (service.getIdService() == ID) {
			unsigned int newPrice;
			std::cout << "Wprowadz nowa cene dla uslugi o ID " << ID << ": ";	//pobieranie nowej ceny od uzytkownika
			std::cin >> newPrice;

			//sprawdzanie poprawnosci danych wejsciowych
			if (std::cin.fail()) {
				std::cerr << "Blad: Nieprawidlowe dane wejsciowe." << std::endl;
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
				return;
			}
			//zmiana ceny uslugi
			service.changePrice(newPrice);
			std::cout << "Zmieniono cene uslugi o ID " << ID << " na " << newPrice << std::endl;
			return;
		}
	}
	std::cout << "Nie znaleziono uslugi o ID " << ID << std::endl;
}

//wyswietlanie uslugi
void Service::displayService() {
	std::cout << "ID: " << ID << ", Nazwa: " << name << ", Cena: " << price << std::endl;
}

//wybor uslugi do modyfikacji	
void PriceList::chooseService() {
	displayPriceList();

	unsigned int ID;
	std::cout << "Wprowadz ID uslugi, ktora chcesz modyfikowac: ";
	std::cin >> ID;

	//sprawdzanie poprawnosci danych wejsciowych
	if (std::cin.fail()) {
		std::cerr << "Blad: Nieprawidlowe dane wejsciowe." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	//szukanie uslugi o podanym ID
	for (Service& service : services) {
		if (service.getIdService() == ID) {
			std::cout << "Wybrano usluge o nr ID: " << ID << std::endl;
			selectedID = ID;
			return;
		}
	}
	std::cout << "Nie znaleziono uslugi o ID " << ID << std::endl;
}

//konstruktor
Service::Service(unsigned int ID, std::string name, unsigned int price) : ID(ID), name(name), price(price) {}