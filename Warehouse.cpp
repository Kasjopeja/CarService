#include "Warehouse.h"

void Warehouse::loadData()
{
	std::vector <Part> warehouseState;

	unsigned int ID;
	std::string name;
	unsigned int amount;
	std::string line;

	std::ifstream file("Magazyn.txt");

	while (std::getline(file, line))
	{
		std::istringstream stream(line);
		stream >> ID >> name >> amount;
		Part part(ID, name, amount);

		warehouseState.push_back(part);
	}

	file.close();

	this->warehouseState = warehouseState;

}

void Warehouse::displayPart()
{
	std::cout << "\n------------------------\n";
	std::cout << "|     Stan magazynu    |\n";
	std::cout << "------------------------\n\n";

	for (int i = 0; i < this->warehouseState.size(); i++)
	{
		this->warehouseState[i].displayPart();
	}
}

void Warehouse::addPart()
{
	std::cout << "DODAWANIE NOWEGO ELEMENTU \n\n";

	std::ofstream file("Magazyn.txt", std::ios::app);

	unsigned int ID = warehouseState.size() +1;
	std::string name;
	unsigned int amount;

	std::cout << "Nazwa: ";
	std::cin >> name;
	std::cout << "Ilosc: ";
	std::cin >> amount;

	Part part(ID, name, amount);
	this->warehouseState.push_back(part);

	file << "\n" << ID << " " << name << " " << amount;
	file.close();
}

void Warehouse::editPart()
{
	std::cout << "EDYTOWANIE ISTNIEJACEGO ELEMENTU \n\n";

	unsigned int amount;
	unsigned int ID;

	std::cout << "ID elementu do edycji: ";
	std::cin >> ID;
	std::cout << std::endl;
	std::cout << "Nowa Ilosc: ";
	std::cin >> amount;

	warehouseState[ID - 1].editPart(amount);

	std::ofstream file("Magazyn.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();

	for (int i = 0; i < warehouseState.size(); i++)
	{
		warehouseState[i].saveChangesToFIle();
	}

}

void Part::displayPart()
{
	std::cout << "ID: " << ID << " \t\tNazwa: " << name << "\t\tIlosc: " << amount << std::endl;
}

void Part::editPart(unsigned int newAmount)
{
	this->amount = newAmount;
}

void Part::saveChangesToFIle() 
{
	std::ofstream file("Magazyn.txt", std::ios::app);
	file << ID << " " << name << " " << amount << "\n";
	file.close();
}


Part::Part(unsigned int ID, std::string name, unsigned int amount) : ID(ID), name(name), amount(amount) {}