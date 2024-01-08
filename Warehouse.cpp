#include "Warehouse.h"

// zaladowanie danych z pliku
void Warehouse::loadData()
{
	std::vector <Part> warehouseState; // przechowywanie wszystkich obiektow klasy Part

	unsigned int ID, amount;
	std::string name, line;

	std::ifstream file("Magazyn.txt");

	while (std::getline(file, line)) // czytanie pliku linia po linii
	{
		std::istringstream stream(line);
		stream >> ID >> name >> amount;
		Part part(ID, name, amount); // stowrzenie obiektu klasy Part z odczytanych danych

		warehouseState.push_back(part); // dodanie utworzoego obiektu klasy Part do vector 
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
	{  // wyswietlanie informacji o kazdym obieckie zawartym w vector warehouseState
		this->warehouseState[i].displayPart();
	}
}

// dodawanie nowego wpisu do warehouseState
void Warehouse::addPart()
{
	std::cout << "DODAWANIE NOWEGO ELEMENTU \n\n";

	std::ofstream file("Magazyn.txt", std::ios::app); // otwieranie pliku zawierajacego informacje o stanie magazynu

	unsigned int ID = warehouseState.size() +1;
	std::string name;
	unsigned int amount;

	// uzytkownik podaje informacje potrzebne do utworzenia npwego obiektu
	std::cout << "Nazwa: ";
	std::cin >> name;
	std::cout << "Ilosc: ";
	std::cin >> amount;

	Part part(ID, name, amount);
	this->warehouseState.push_back(part); // aktualizowanie vectiora warehouseState

	file << "\n" << ID << " " << name << " " << amount; // aktualizowanie informacji zawartych w pliku
	file.close();
}

// edycja inormacji o istniejacym wpisie
void Warehouse::editPart()
{
	std::cout << "EDYTOWANIE ISTNIEJACEGO ELEMENTU \n\n";

	unsigned int amount;
	unsigned int ID;

	// uzytkownik wybiera który obiekt chce edytowaæ i jak on ma siê zmieniæ
	std::cout << "ID elementu do edycji: ";
	std::cin >> ID;
	std::cout << std::endl;
	std::cout << "Nowa Ilosc: ";
	std::cin >> amount;

	// zapisywanie zmian do vectiora
	warehouseState[ID - 1].editPart(amount);

	//zapisywanie zmian do pliku
	std::ofstream file("Magazyn.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();
	for (int i = 0; i < warehouseState.size(); i++)
	{
		warehouseState[i].saveChangesToFIle();
	}

}

// dodawanie nowego wpisu do orderState
void Warehouse::addOrder()
{
	std::cout << "SK£ADANIE ZAMOWIENIA \n\n";

	std::string name;
	unsigned int amount;

	// uzytkownik podaje informacje potrzebne do utworzenia npwego obiektu
	std::cout << "Nazwa przedmiotu do zamówienia: ";
	std::cin >> name;
	std::cout << "Ilosc: ";
	std::cin >> amount;

	Part part(NULL, name, amount);
	this->orderState.push_back(part);
}

void Warehouse::displayOrders()
{
	//przykladowe zamowienia
	Part part1(NULL, "kolcki hamulcowe", 3);
	this->orderState.push_back(part1);
	Part part2(NULL, "swieca", 5);
	this->orderState.push_back(part2);

	std::cout << "ZLOZONE ZAMOWIENIA \n\n";

	for (int i = 0; i < this->orderState.size(); i++)
	{
		this->orderState[i].displayPart();
	}
}

void Part::displayPart()
{
	// wyswietlanie informacji o pojedynczym obiekcie klasy Part
	std::cout << "ID: " << ID << " \t\tNazwa: " << name << "\t\tIlosc: " << amount << std::endl;
}

void Part::editPart(unsigned int newAmount)
{
	this->amount = newAmount;
}

void Part::saveChangesToFIle() 
{
	// zapisywanie zmian obiektu klasy Part do pliku
	std::ofstream file("Magazyn.txt", std::ios::app);
	file << ID << " " << name << " " << amount << "\n";
	file.close();
}


Part::Part(unsigned int ID, std::string name, unsigned int amount) : ID(ID), name(name), amount(amount) {}

unsigned int Part::getID() const {
	return ID;
}
std::string Part::getName() const {
	return name;
}
unsigned int Part::getAmount() const {
	return amount;
}