//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#include "Warehouse.h"

std::vector <Parts> Warehouse::Wczytaj()
{
	std::vector <Parts> stanMagazynu;

	std::ifstream plik("Magazyn");

	unsigned int ID;
	std::string name;
	unsigned int amount;

	std::string linia;

	while (std::getline(plik, linia))
	{
		Parts part(ID, name, amount);

		stanMagazynu.push_back(part);

	}

	return stanMagazynu;
}

Parts::Parts(unsigned int ID, std::string name, unsigned int amount) : ID(ID), name(name), amount(amount) {}