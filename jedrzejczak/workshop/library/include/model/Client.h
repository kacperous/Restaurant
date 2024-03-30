#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;

public:
    Client();
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID);
    ~Client();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPersonalID() const;
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setPersonalID(const std::string &personalID);

    std::string getInfo() const;
};

#endif // CLIENT_H
