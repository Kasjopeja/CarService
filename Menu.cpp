#include "Menu.h"
#include <iostream>
//#include <conio.h>


Menu::Menu() : selectedOption(1) {}
  
int Menu::showAllOpions(int wariant)
{
    system("cls");
    std::cout << "Wybierz akcjê:\n";

    switch (wariant)
    {
    case 0:

        std::cout << (selectedOption == 1 ? "> " : "  ") << "Pracownik Biura\n";
        std::cout << (selectedOption == 2 ? "> " : "  ") << "Mehcanik\n";

        return 2;
        break;

    case 1:

        std::cout << (selectedOption == 1 ? "> " : "  ") << "Zarzadzaj magazynem\n";
        std::cout << (selectedOption == 2 ? "> " : "  ") << "Zarzadzaj cennikiem\n";
        std::cout << (selectedOption == 3 ? "> " : "  ") << "Wystaw fakture\n";
        std::cout << (selectedOption == 4 ? "> " : "  ") << "Wyjscie\n";

        return 4;
        break;

    case 2:

        std::cout << (selectedOption == 1 ? "> " : "  ") << "Zarzadzaj magazynem\n";
        std::cout << (selectedOption == 2 ? "> " : "  ") << "Zarzadzaj kalendarzem\n";
        std::cout << (selectedOption == 3 ? "> " : "  ") << "Wyjœcie\n";

        return 3;
        break;
    }
}

bool Menu::navigate(int maxOption)
{
    char key;
    //key = _getch();
    std::cin >> key;

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
    }

    return 0;
}

int Menu::getSelectedOption()
{
	return selectedOption;
}