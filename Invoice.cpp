#include <iostream>
#include <fstream>
#include <string>

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

    return 0;
}