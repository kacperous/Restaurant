#include <iostream>
using namespace std;
class Client{
private:
    string firstName;
    string lastName;
    string personalID;

public:
    Client(string fName, string lName, string ID) : firstName(fName), lastName(lName), personalID(ID) {
    }
    ~Client(){
    }
    string getFirstName() const;
    void setFirstName(const string& fName);
    string getLastName() const;
    void setLastName(const string& lName);
    string getPersonalID() const;
    void setPersonalID(const string& ID);
    string getInfo();
private:
    void printDiagnostic(string message);
};