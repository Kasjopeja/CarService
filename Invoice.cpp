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

void Invoice::addPartsData() {
	std::cout << "DODAWANIE CZESCI DO FAKTURY \n\n";

	std::ofstream file("faktura.txt", std::ios::app); // otwieranie pliku zawierajacego fakture
	std::string name;
	int tmp;
	//wybor dostepnych opcji
	std::cout << "1. Dodanie czesci do faktury" << std::endl;
	std::cout << "2. Wyjscie" << std::endl;

	
		std::cout << "Ile czesci zostaje wprowadzone: ";
		std::cin >> tmp;
		for (int i = 0; i < tmp; i++) {				// petla pozwalajca wprowadzic kilka czesci za jednym razem
			std::cout << "Nazwa wykorzystanej czesci: ";
			std::cin >> name;
			file << "Czesc: " << name << std::endl;	//wprowadzenie danych do pliku
		}
		file << "-------------------------" << std::endl;
	file.close();
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

int sum = 0;
int subpart = 0;

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


