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
    invoiceFile << "Imiê: " << client.name << std::endl;
    invoiceFile << "Nazwisko: " << client.lastname << std::endl;
    invoiceFile << "Adres mailowy: " << client.mailAdress << std::endl;
    invoiceFile << "Numer telefonu: " << client.phoneNumber << std::endl;
    invoiceFile << "-------------------------" << std::endl;
}

void Invoice::addPartsData(const Parts& parts) {
    std::ofstream invoiceFile("invoice.txt", std::ios::app);

    if (invoiceFile.is_open()) {
        invoiceFile << "ID: " << parts.ID << std::endl;
        invoiceFile << "Name: " << parts.name << std::endl;
        invoiceFile << "Amount: " << parts.amount << std::endl;
        invoiceFile << "-------------------------" << std::endl;
    }
}

void Print(const std::string& fileName){
    // otworzenie pliku do odczytu
    std::ifstream plik(fileName);

    if (plik.is_open()) {
        std::string linia;

        // odczytannie i wypisanie zawartoœæ pliku linia po linii
        while (std::getline(plik, linia)) {
            std::cout << linia << std::endl;
        }

        // Zamknie plik
        plik.close();
    }
    else {
        std::cerr << "B³¹d: Nie uda³o siê otworzyæ pliku do odczytu." << std::endl;
    }
}

int main() {
    Client client;

    // Wprowadzanie dane klienta
    std::cout << "Podaj imiê klienta: ";
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
        std::cerr << "B³¹d: Nie uda³o siê otworzyæ pliku do zapisu." << std::endl;
        return 1;
    }
    // Podanie nazwê pliku, który chcemy odczytaæ
    std::string fileName = "faktura.txt";

    // Wywo³anie funkcji
    Print(fileName);



    return 0;
}