#include "OfficeWorker.h"
#include <iostream>

OfficeWorker::OfficeWorker(const std::string& name) : user(name) {}

void OfficeWorker::manageWarehouse() {
    std::cout << "Zarządzanie magazynem\n";
    // implementacja
}

void OfficeWorker::managePriceList() {
    std::cout << "Zarządzanie cennikiem\n";
    // implementacja
}

void OfficeWorker::issueInvoice() {
    std::cout << "Wystawianie faktury\n";
    // implementacja
}