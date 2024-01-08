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

void Invoice::addCharge()
{
	std::cout << "DODAWANIE NALEZNOSCI DO FAKTURY \n\n";

	std::ofstream file("faktura.txt", std::ios::app); // otwieranie pliku zawierajacego fakture

	//wybor dostepnych opcji
	std::cout << "1. Dodanie kosztu skladowego" << std::endl;
	std::cout << "2. Dodaj ³acznej nalennosci do faktury" << std::endl;
	std::cout << "3. Wyjscie" << std::endl;

	int choice;	//wprowadzenie numeru wybranej opcji
	std::cin >> choice;
	int sum=0;
	int subpart=0;

	switch (choice)
	{
	case 1:
		std::cout << "Podaj koszt skladowy: " << std::endl;
		std::cin >> subpart;
		sum = sum + subpart;	//dodawanie kosztu skladowego do calkowitej naleznosci
		break;
	case 2:
		file << "Ca³kowita naleznosc za us³ugi: " << sum << std::endl;	//wprowadzenie danych do pliku
		file << "-------------------------" << std::endl;
		break;
	case 3:
		return;
	}
	file.close();
}


