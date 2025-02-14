#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\lusia\source\repos\CarService\Invoice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InvoiceUnitTest
{
    TEST_CLASS(InvoiceTest)
    {
    public:
        TEST_METHOD(AddClientTest)
        {
            MockInvoice invoice;

            // Przygotowanie strumienia wejściowego dla testu
            std::istringstream input("Kamil\nRaj\nkami.raj@example.com\n123456789\n");

            // Przechwycenie std::cin i przekierowanie do strumienia wejściowego
            std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

            // Oczekiwane wywołanie funkcji addClient
            Assert::ExpectException<Platform::Exception^>(
                [&]() { invoice.addClient(); },
                L"addClient method was not called once."
            );

            // Przywrócenie std::cin do normalnego stanu
            std::cin.rdbuf(oldCin);

            // Przygotowanie strumienia wyjściowego dla testu
            std::ostringstream output;

            // Przechwycenie std::cout i przekierowanie do strumienia wyjściowego
            std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

            // Wywołanie funkcji, która wypisuje dane do std::cout
            invoice.addClient();

            // Przywrócenie std::cout do normalnego stanu
            std::cout.rdbuf(oldCout);

            // Oczekiwane wyjście
            std::string expectedOutput = "DODAWANIE KLIENTA DO FAKTURY \n\nImie: Nazwisko: Mail: Telefon: -------------------------\n";

            // Porównanie oczekiwanego wyjścia ze strumienia wyjściowego
            Assert::AreEqual(expectedOutput.c_str(), output.str().c_str(), L"Unexpected output.");
        }
    };
}