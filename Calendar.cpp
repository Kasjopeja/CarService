//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

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
    std::cout << "Events in Calendar:\n";
    for (size_t i = 0; i < events.size(); ++i) {
        std::cout << "Event " << i + 1 << ":\n";
        events[i].displayEvent();
        std::cout << "-------------------------\n";
    }
}