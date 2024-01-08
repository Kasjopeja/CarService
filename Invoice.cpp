#include <iostream>
#include <fstream>
#include <string>
#include "Invoice.h"
#include "Event.h"
#include "Warehouse.h"

void Invoice::addClient()
{
	std::cout << "DODAWANIE KLIENTA DO FAKTURY \n\n";

	std::ofstream file("faktura.txt", std::ios::app); // otwieranie pliku zawierajacego fakture
	std::string name;
	std::string lastname;
	std::string mailAddres;
	std::string phoneNumber;
	

	// uzytkownik podaje informacje o kliencie
	std::cout << "Imie: ";
	std::cin >> name;
	std::cout << "Nazwisko: ";
	std::cin >> lastname;
	std::cout << "Mail: ";
	std::cin >> mailAddres;
	std::cout << "Telefon: ";
	std::cin >> phoneNumber;


	// aktualizowanie informacji zawartych w pliku
	file << "Imie: " << name << std::endl;
	file << "Imie: " << lastname << std::endl;
	file << "Imie: " << mailAddres << std::endl;
	file << "Imie: " << phoneNumber << std::endl;
	file.close();
}

void Invoice::addPartsData(const Part& part, unsigned int userEnteredID) {
	if (part.getID() == userEnteredID) {
		std::ofstream file("faktura.txt", std::ios::app);
		if (file.is_open()) {
			file << "ID: " << part.getID() << std::endl;
			file << "Nazwa: " << part.getName() << std::endl;
			file << "Iloœæ: " << part.getAmount() << std::endl;
			file << "-------------------------" << std::endl;
			file.close();
		}
	}
}



