#ifndef CARSERVICE_CALENDAR_H
#define CARSERVICE_CALENDAR_H

#include <vector>
#include "Event.h"

// Klasa reprezentująca kalendarz napraw samochodów.
class Calendar {
public:
    // Metoda dodająca nowe wydarzenie do kalendarza.
    void addEvent(const Event& event);

    // Metoda usuwająca wydarzenie z kalendarza na podstawie indeksu.
    void removeEvent(int index);

    // Metoda wyświetlająca wszystkie wydarzenia w kalendarzu.
    void displayEvents() const;

    // Metoda zwracająca wektor wszystkich wydarzeń w kalendarzu.
    std::vector<Event> getEvents() const;

private:
    std::vector<Event> events; // Wektor przechowujący wydarzenia w kalendarzu.
};

#endif //CARSERVICE_CALENDAR_H
