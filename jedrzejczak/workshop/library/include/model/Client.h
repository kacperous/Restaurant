#pragma once
#include <string>

class Client {
public:
    // Konstruktor parametrowy (zakładamy usunięcie konstruktora bezparametrowego)
    Client(std::string firstName, std::string lastName, std::string personalID);

    // Destruktor
    ~Client();

    // Metoda getInfo zwracająca informacje o kliencie
    std::string getInfo() const;

    // Gettery
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPersonalID() const;

    // Settery
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setPersonalID(const std::string& personalID);

private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
};

