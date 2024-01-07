#include "Calendar.h"

// Metoda dodająca nowe wydarzenie do kalendarza.
void Calendar::addEvent(const Event& event) {
    events.push_back(event);    // Dodaje obiekt 'event' do wektora przechowującego usterki
}

// Metoda usuwająca wydarzenie z kalendarza na podstawie indeksu.
void Calendar::removeEvent(int index) {
    // Sprawdzenie, czy podane przez użytkownika ID nie jest poza zakresem
    if (index >= 0 && index < events.size()) {
        events.erase(events.begin() + index);   // Usunięcie z wektora
    }
}

// Metoda wyświetlająca wszystkie wydarzenia w kalendarzu.
void Calendar::displayEvents() const {
    std::cout << "\n------------------------\n";
    std::cout << "| Naprawy w kalendarzu |\n";
    std::cout << "------------------------\n";
    for (size_t i = 0; i < events.size(); ++i) {
        std::cout << "ID: " << i + 1 << std::endl;
        events[i].displayEvent();
        std::cout << "------------------------\n";
    }
    std::cout << std::endl;
}

// Metoda zwracająca wektor wszystkich wydarzeń w kalendarzu.
std::vector<Event> Calendar::getEvents() const {
    return events;
}
