#include "Calendar.h"

void Calendar::addEvent(const Event& event) {
    events.push_back(event);
}

void Calendar::removeEvent(int index) {
    if (index >= 0 && index < events.size()) {
        events.erase(events.begin() + index);
    }
}

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

std::vector<Event> Calendar::getEvents() const {
    return events;
}