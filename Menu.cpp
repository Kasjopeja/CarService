#include "Menu.h"
#include <iostream>

#ifdef _WIN32
    #include <conio.h>
    bool isWin = true;
#elif
    bool isWin = false;
#endif


Menu::Menu() : selectedOption(1) {}
  
int Menu::showAllOpions(int wariant)
{
    system("cls");

    switch (wariant)
    {
    case 0:

        std::cout << "CAR SERVICE v0.1 \n " << std::endl;

        std::cout << "LOGOWANIE:\n";

        std::cout << (selectedOption == 1 ? "> " : "  ") << "Pracownik Biura\n";
        std::cout << (selectedOption == 2 ? "> " : "  ") << "Mechanik\n";

        return 2;
        break;

    case 1:

        std::cout << "MENU GLOWNE:\n \n";

        std::cout << (selectedOption == 1 ? "> " : "  ") << "Zarzadzaj magazynem\n";
        std::cout << (selectedOption == 2 ? "> " : "  ") << "Zarzadzaj cennikiem\n";
        std::cout << (selectedOption == 3 ? "> " : "  ") << "Wystaw fakture\n";
        std::cout << (selectedOption == 4 ? "> " : "  ") << "Wyjscie\n";

        return 4;
        break;

    case 2:

        std::cout << "MENU GLOWNE:\n \n";

        std::cout << (selectedOption == 1 ? "> " : "  ") << "Zarzadzaj magazynem\n";
        std::cout << (selectedOption == 2 ? "> " : "  ") << "Zarzadzaj kalendarzem\n";
        std::cout << (selectedOption == 3 ? "> " : "  ") << "Wyjœcie\n";

        return 3;
        break;

    case 3:

        std::cout << "STAN MAGAZYNU \n" << std::endl;

        std::cout << (selectedOption == 1 ? "> " : "  ") << "Wyswietl stan magazynu\n";
        std::cout << (selectedOption == 2 ? "> " : "  ") << "Dodaj nowy element\n";
        std::cout << (selectedOption == 3 ? "> " : "  ") << "Edytuj istniejacy element\n";
        std::cout << (selectedOption == 4 ? "> " : "  ") << "Wyjscie\n";

        return 4;
        break;
    }
}

bool Menu::navigate(int maxOption)
{
    char key;

    if (isWin) key = _getch();
    else std::cin >> key;

    switch (key) {
    case 'w': // Strza³ka w górê
        selectedOption = (selectedOption > 1) ? selectedOption - 1 : maxOption;
        break;
    case 's': // Strza³ka w dó³
        selectedOption = (selectedOption < maxOption) ? selectedOption + 1 : 1;
        break;
    case 'd':
        return 1;
    case 'a':
        selectedOption = maxOption;
        return 1;
    default:
        return 1;
    
    }

    return 0;
}

int Menu::getSelectedOption()
{
	return selectedOption;
}