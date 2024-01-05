#ifndef CARSERVICE_EVENT_H
#define CARSERVICE_EVENT_H

#include <string>
#include <iostream>

class Event {
public:
    Event(const std::string& type, const std::string& reportDate, const std::string& plannedDate, const std::string& status);  // konstruktor
    void displayEvent() const;  // wyświetlanie każdego z pól z pojedynczego eventu
private:
    std::string type;   // rodzaj zlecenia
    std::string reportDate; // data zgłoszenia
    std::string plannedDate;    // planowana data wykonania
    std::string status; // status zlecenia
};


#endif //CARSERVICE_EVENT_H
