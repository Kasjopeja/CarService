#ifndef CARSERVICE_USER_H
#define CARSERVICE_USER_H


#include <string>

class User {
public:
    User(const std::string& name, std::string& role);
    std::string getRole() const;
private:
    std::string name;
    std::string role;
};


#endif //CARSERVICE_USER_H
