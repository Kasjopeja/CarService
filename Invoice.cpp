#include "Invoice.h"
#include <string>

void Invoice::addClient() {
	std::string name;
	std::string lastname;
	int phoneNumber;
	std::string mailAdress;

	std::cout << "Imie klienta: ";
	std::cin >> name;
	std::cout <<" " << "Nazwisko kleinta: ";
	std::cin >> lastname;
	std::cout<< std::endl << "Numer telefonu klient: ";
	std::cin >> phoneNumber;
	std::cout << std::endl << "Adres mail klienta: ";
	std::cin >> mailAdress;

	//Jutro rano poprawie, zeby to wszytko bylo zapisywane do pliku, teraz ide spac xoxo

}