#include "OfficeWorker.h"
#include <iostream>

OfficeWorker::OfficeWorker(const std::string& name) : User(name) {}

void OfficeWorker::manageWarehouse() {
    
    while (true)
    {
        //system("cls");

        std::cout << "STAN MAGAZYNU " << std::endl;

        std::cout << "1. Wyswietl stan magazynu\n";
        std::cout << "2. Dodaj nowy element\n";
        std::cout << "3. Edytuj istniejacy element\n";
        std::cout << "4. Wyjscie\n";

        Warehouse warehouse;
        warehouse.Wczytaj();

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:

            warehouse.Wyswietl();
            std::cin.ignore();
            break;
        case 2:
            warehouse.Dodaj();
            break;
        case 3:
            warehouse.Edytuj();
            break;

        case 4:
            return;
        }
    }

}

void OfficeWorker::managePriceList() {
    
    PriceList priceList;    //utworzenie cennika

    //tworzenie uslug domyslnych
    Service service1(1, "Wymiana opon", 100);
    Service service2(2, "Wymiana oleju", 200);
    Service service3(3, "Wymiana klockow", 300);
    Service service4(4, "Wymiana tarcz hamulcowych", 400);
    //dodawanie do cennika utworzonych uslug
    priceList.addService(service1);
    priceList.addService(service2);
    priceList.addService(service3);
    priceList.addService(service4);

    int choice;
    do {
        std::cout << "\nZarzadzenie cennikiem. Wybierz co chcesz zrobic:" << std::endl;
        std::cout << "1. Wyswietl cennik." << std::endl;
        std::cout << "2. Dodaj usluge." << std::endl;
        std::cout << "3. Usun usluge." << std::endl;
        std::cout << "4. Zmiana ceny uslugi." << std::endl;
        std::cout << "0. Wyjscie." << std::endl;
        std::cout<< "Wybor: ";
        std::cin >> choice;
        system("cls");
        switch (choice) {
		case 1:
            //wyswietlanie cennika
            priceList.displayPriceList();
			break;
		case 2:
            //dodawanie uslugi
            priceList.addService();
			break;
		case 3:
            //usuwanie uslugi
            priceList.displayPriceList();
            unsigned int ID;
            std::cout << "Wprowadz ID uslugi, ktora chcesz usunac: ";
            std::cin >> ID;
            priceList.removeService(ID);
			break;
		case 4:
            //zmiana ceny uslugi
            priceList.chooseService();
            priceList.changePrice();
			break;
		case 0:
            std::cout<<"Wyjscie z zarzadzania cennikiem."<<std::endl;
			break;
		default:
			std::cout << "Nie ma takiej opcji w menu." << std::endl;
			break;
		}
    } while (choice != 0);
}

void OfficeWorker::issueInvoice() {
    std::cout << "Wystawianie faktury\n";
    // implementacja
}