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
	file << "-------------------------" << std::endl;

	file.close();
}

void Invoice::addPartsData(const Part& part) {
	// Przyjmujemy dane bezpoœrednio z obiektu Part
	unsigned int partID = part.getID();
	std::string partName = part.getName();
	unsigned int partAmount = part.getAmount();

	// Otwierami plik do zapisu
	std::ofstream file("faktura.txt", std::ios::app);

	if (file.is_open()) {
		// Wypisujemy dane do pliku
		file << "ID: " << partID << std::endl;
		file << "Nazwa: " << partName << std::endl;
		file << "-------------------------" << std::endl;

		// Zamknij plik
		file.close();

		std::cout << "Dane zapisane do pliku: faktura.txt" << std::endl;
	}
	else {
		std::cerr << "B³¹d: Nie uda³o siê otworzyæ pliku do zapisu." << std::endl;
	}
}

void Invoice::addEventData()
{
	std::cout << "DODAWANIE ZLECENIA DO FAKTURY \n\n";

	std::ofstream file("faktura.txt", std::ios::app); // otwieranie pliku zawierajacego fakture
	std::string name;
	std::string finishDate;
	


	// uzytkownik podaje informacje o zleceniu
	std::cout << "Nazwa zlecenia: ";
	std::cin >> name;
	std::cout << "Data wykonania: ";
	std::cin >> finishDate;
	



	// aktualizowanie informacji zawartych w pliku
	file << "Zlecenie: " << name << std::endl;
	file << "Data wykonania: " << finishDate << std::endl;
	file << "-------------------------" << std::endl;

	file.close();
}




