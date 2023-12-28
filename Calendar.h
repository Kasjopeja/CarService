//
// Created by Jakub Wawrzyczek on 25/12/2023.
//

#ifndef CARSERVICE_CALENDAR_H
#define CARSERVICE_CALENDAR_H


#include <vector>
#include "Event.h"

class Calendar {
public:
    void addEvent(const Event& event);
    void removeEvent(int index);
    void displayEvents() const;
private:
    std::vector<Event> events;
};


#endif //CARSERVICE_CALENDAR_H
