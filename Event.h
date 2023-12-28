//
// Created by Jakub Wawrzyczek on 28/12/2023.
//

#ifndef CARSERVICE_EVENT_H
#define CARSERVICE_EVENT_H

#include <string>
#include <iostream>

class Event {
public:
    Event(const std::string& type, const std::string& reportDate, const std::string& plannedDate);
    void displayEvent() const;
private:
    std::string type;
    std::string reportDate;
    std::string plannedDate;
};


#endif //CARSERVICE_EVENT_H
