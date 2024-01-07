#include <iostream>
#include <fstream>
#include <string>
#include "Invoice.h"
#include "Event.h"

struct Client {
    std::string name;
    std::string lastname;
    std::string mailAdress;
    std::string phoneNumber;
};


void addClient(const Client& client, std::ofstream& invoiceFile) {
    invoiceFile << "Imi�: " << client.name << std::endl;
    invoiceFile << "Nazwisko: " << client.lastname << std::endl;
    invoiceFile << "Adres mailowy: " << client.mailAdress << std::endl;
    invoiceFile << "Numer telefonu: " << client.phoneNumber << std::endl;
    invoiceFile << "-------------------------" << std::endl;
}

void Invoice::addPartsData(const Parts& parts, unsigned int targetID) {
    if (parts.ID == targetID) {
        // Tutaj mo�esz wykorzysta� przekazane dane wed�ug potrzeb
        std::cout << "ID: " << parts.ID << std::endl;
        std::cout << "Nazwa: " << parts.name << std::endl;
        std::cout << "Ilo��: " << parts.amount << std::endl;

        // Mo�esz teraz u�y� tych danych w klasie Invoice do dalszej obr�bki

        // Otw�rz plik do zapisu
        std::ofstream invoiceFilebbgb("invoice.txt", std::ios::app);

        if (file.is_open()) {
            // Zapisz dane do pliku
            file << "ID: " << parts.ID << std::endl;
            file << "Nazwa: " << parts.name << std::endl;
            file << "Ilo��: " << parts.amount << std::endl;
            file << "-------------------------" << std::endl;

            // Zamknij plik
            file.close();

            std::cout << "Dane zapisane do pliku: invoice.txt" << std::endl;
        }
        else {
            std::cerr << "B��d: Nie uda�o si� otworzy� pliku do zapisu." << std::endl;
        }
    }
}

void Print(const std::string& fileName){
    // otworzenie pliku do odczytu
    std::ifstream plik(fileName);

    if (plik.is_open()) {
        std::string linia;

        // odczytannie i wypisanie zawarto�� pliku linia po linii
        while (std::getline(plik, linia)) {
            std::cout << linia << std::endl;
        }

        // Zamknie plik
        plik.close();
    }
    else {
        std::cerr << "B��d: Nie uda�o si� otworzy� pliku do odczytu." << std::endl;
    }
}

int main() {
    Client client;

    // Wprowadzanie dane klienta
    std::cout << "Podaj imi� klienta: ";
    std::getline(std::cin, client.name);

    std::cout << "Podaj nazwisko klienta: ";
    std::getline(std::cin, client.lastname);

    std::cout << "Podaj adres mailowy klienta: ";
    std::getline(std::cin, client.mailAdress);

    std::cout << "Podaj numer telefonu klienta: ";
    std::getline(std::cin, client.phoneNumber);

    // Otwieranie plik do zapisu
    std::ofstream plik("faktura.txt", std::ios::app);

    if (plik.is_open()) {
        // Dodawanie danych klienta do faktury
        addClient(client, plik);

        // Zamknanie plik
        plik.close();

        std::cout << "Dane klienta dodane do faktury i zapisane do pliku." << std::endl;
    }
    else {
        std::cerr << "B��d: Nie uda�o si� otworzy� pliku do zapisu." << std::endl;
        return 1;
    }
    // Podanie nazw� pliku, kt�ry chcemy odczyta�
    std::string fileName = "faktura.txt";

    // Wywo�anie funkcji
    Print(fileName);



    return 0;
}