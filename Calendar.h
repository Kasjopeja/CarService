#ifndef CARSERVICE_CALENDAR_H
#define CARSERVICE_CALENDAR_H


#include <vector>
#include "Event.h"

class Calendar {
public:
    void addEvent(const Event& event);  // dodawanie usterki do kalendarza
    void removeEvent(int index);    // usuwanie usterki z kalendarza
    void displayEvents() const; // wyświetlanie kalendarza

    std::vector<Event> getEvents() const;   // getter do wyciągania usterek (są w polu prywatnym)
private:
    std::vector<Event> events;  // usterki w vectorze
};


#endif //CARSERVICE_CALENDAR_H
