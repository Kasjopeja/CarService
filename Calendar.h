#ifndef CARSERVICE_CALENDAR_H
#define CARSERVICE_CALENDAR_H


#include <vector>
#include "Event.h"

class Calendar {
public:
    void addEvent(const Event& event);
    void removeEvent(int index);
    void displayEvents() const;

    std::vector<Event> getEvents() const;
private:
    std::vector<Event> events;
};


#endif //CARSERVICE_CALENDAR_H
