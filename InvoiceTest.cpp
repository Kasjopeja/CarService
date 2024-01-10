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

            // Przygotowanie strumienia wej�ciowego dla testu
            std::istringstream input("Kamil\nRaj\nkami.raj@example.com\n123456789\n");

            // Przechwycenie std::cin i przekierowanie do strumienia wej�ciowego
            std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

            // Oczekiwane wywo�anie funkcji addClient
            Assert::ExpectException<Platform::Exception^>(
                [&]() { invoice.addClient(); },
                L"addClient method was not called once."
            );

            // Przywr�cenie std::cin do normalnego stanu
            std::cin.rdbuf(oldCin);

            // Przygotowanie strumienia wyj�ciowego dla testu
            std::ostringstream output;

            // Przechwycenie std::cout i przekierowanie do strumienia wyj�ciowego
            std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

            // Wywo�anie funkcji, kt�ra wypisuje dane do std::cout
            invoice.addClient();

            // Przywr�cenie std::cout do normalnego stanu
            std::cout.rdbuf(oldCout);

            // Oczekiwane wyj�cie
            std::string expectedOutput = "DODAWANIE KLIENTA DO FAKTURY \n\nImie: Nazwisko: Mail: Telefon: -------------------------\n";

            // Por�wnanie oczekiwanego wyj�cia ze strumienia wyj�ciowego
            Assert::AreEqual(expectedOutput.c_str(), output.str().c_str(), L"Unexpected output.");
        }
    };
}