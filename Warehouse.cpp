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
	std::cout << "EDYTOWANIE ISTNIEJACEGO ELEMENTU \n\n";

	unsigned int amount;
	unsigned int ID;

	std::cout << "ID elementu do edycji: ";
	std::cin >> ID;
	std::cout << std::endl;
	std::cout << "Nowa Ilosc: ";
	std::cin >> amount;

	stanMagazynu[ID - 1].Edytuj(amount);

	std::ofstream plik("Magazyn.txt", std::ofstream::out | std::ofstream::trunc);
	plik.close();

	for (int i = 0; i < stanMagazynu.size(); i++)
	{
		stanMagazynu[i].Zapisz();
	}

}

void Parts::Wyswietl()
{
	std::cout << "ID: " << ID << " \t\tNazwa: " << name << "\t\tIlosc: " << amount << std::endl;
}

void Parts::Edytuj(unsigned int newAmount)
{
	this->amount = newAmount;
}

void Parts::Zapisz() 
{
	std::ofstream plik("Magazyn.txt", std::ios::app);
	plik << ID << " " << name << " " << amount << "\n";
	plik.close();
}


Parts::Parts(unsigned int ID, std::string name, unsigned int amount) : ID(ID), name(name), amount(amount) {}