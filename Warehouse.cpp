//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#include "Warehouse.h"

void Warehouse::Wczytaj()
{
	std::vector <Parts> stanMagazynu;

	unsigned int ID;
	std::string name;
	unsigned int amount;
	std::string linia;

	std::ifstream plik("Magazyn.txt");

	while (std::getline(plik, linia))
	{
		std::istringstream stream(linia);
		stream >> ID >> name >> amount;
		Parts part(ID, name, amount);

		stanMagazynu.push_back(part);
	}

	plik.close();

	this->stanMagazynu = stanMagazynu;

}

void Warehouse::Wyswietl()
{
	for (int i = 0; i < this->stanMagazynu.size(); i++)
	{
		this->stanMagazynu[i].Wyswietl();
	}
}

void Warehouse::Dodaj()
{
	std::cout << "DODAWANIE NOWEGO ELEMENTU \n\n";

	std::ofstream plik("Magazyn.txt", std::ios::app);

	unsigned int ID = stanMagazynu.size() +1;
	std::string name;
	unsigned int amount;

	std::cout << "Nazwa: ";
	std::cin >> name;
	std::cout << "Ilosc: ";
	std::cin >> amount;

	Parts part(ID, name, amount);
	this->stanMagazynu.push_back(part);

	plik << "\n" << ID << " " << name << " " << amount;
	plik.close();
}

void Warehouse::Edytuj()
{

}

void Parts::Wyswietl()
{
	std::cout << "ID: " << ID << " \t Nazwa: " << name << "\t Ilosc: " << amount << std::endl;
}

void Parts::Edytuj()
{

}

Parts::Parts(unsigned int ID, std::string name, unsigned int amount) : ID(ID), name(name), amount(amount) {}