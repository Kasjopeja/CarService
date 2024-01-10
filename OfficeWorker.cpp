#include "OfficeWorker.h"
#include "Invoice.h"
#include "Event.h"
#include "Warehouse.h"
#include <iostream>

OfficeWorker::OfficeWorker(const std::string& name, std::string& role) : User(name, role) {}

void OfficeWorker::manageWarehouse() {
    
    while (true)
    {
        // wyswietlanie menu wyboru
        std::cout << "STAN MAGAZYNU " << std::endl;

        std::cout << "0. Wyswietl stan zamowien\n";
        std::cout << "1. Wyswietl stan magazynu\n";
        std::cout << "2. Dodaj nowy element\n";
        std::cout << "3. Edytuj istniejacy element\n";
        std::cout << "4. Wyjscie\n";

        // zaladowanie informacji o stanie magazynu do programu
        Warehouse warehouse;
        warehouse.loadData();

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            // wysiwtlanie informacji o stanie zamowien
            warehouse.displayOrders();
            std::cin.ignore();
            break;
        case 1:
            // wysiwtlanie informacji o stanie magazynu
            warehouse.displayPart();
            std::cin.ignore();
            break;
        case 2:
            // dodawanie nowego elementu do magazynu - towrzenie obiektu klasy Part
            warehouse.addPart();
            break;
        case 3:
            // edytowanie informacji o stanie magazynu - konkretnym obieckie klasy Part 
            warehouse.editPart();
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
    while (true)
    {
        //system("cls");

        std::cout << "WYSTAWIANIE FAKTURY " << std::endl;

        std::cout << "1. Dodanie klienta do faktury" << std::endl;
        std::cout << "2. Dodaj zlecenia do faktury" << std::endl;
        std::cout << "3. Dodanie czesci do faktury" << std::endl;
        std::cout << "4. Dodanie naleznosci do faktury" << std::endl;
        std::cout << "5. Wyjscie" << std::endl;

        Invoice invoice;

        int choice;
        std::cin >> choice;
  
        switch (choice)
        {
        case 1:
            invoice.addClient();
            std::cin.ignore();
            break;
        case 2:
            invoice.addEventData();
            std::cin.ignore();
            break;
        case 3:
            invoice.addPartsData();
            std::cin.ignore();
            break;
        case 4:
            invoice.addCharge();
            std::cin.ignore();
            break;
        case 5:
            return;
        }
    }
    // implementacja
}