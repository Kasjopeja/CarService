#include "Calendar.h"

void Calendar::addEvent(const Event& event) {
    events.push_back(event);    // dodawanie obiektu 'event' do vectora
}

void Calendar::removeEvent(int index) {
    // sprawdzenie, czy podane ID nie jest za duże lub, czy vector nie jest pusty
    if (index >= 0 && index < events.size()) {
        events.erase(events.begin() + index);   // usunięcie usterki z vectora
    }
}

void Calendar::displayEvents() const {
    std::cout << "\n------------------------\n";
    std::cout << "| Naprawy w kalendarzu |\n";
    std::cout << "------------------------\n";
    // pętla iterująca po i od 0 do maksymalnego ID
    for (size_t i = 0; i < events.size(); ++i) {
        std::cout << "ID: " << i + 1 << std::endl; // ID + 1 bo system liczy od 0 a użytkownikowi podajemy od 1
        events[i].displayEvent();   // wywołanie metody, która wyświetla wszystkie dane usterki
        std::cout << "------------------------\n";
    }
    std::cout << std::endl;
}

std::vector<Event> Calendar::getEvents() const {
    return events;  // getter - zwraca usterki w ten sposób, bo są w polu prywatnym
}