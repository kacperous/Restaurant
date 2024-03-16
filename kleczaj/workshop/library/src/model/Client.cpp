#include "model/Client.h"
using namespace std;

string Client::getFirstName() const {
    return firstName;
}
void Client::setFirstName(const string& fName) {
    if (!fName.empty()) {
        firstName = fName;
    }
}
string Client::getLastName() const {
    return lastName;
}
void Client::setLastName(const string& lName) {
    if (!lName.empty()) {
        lastName = lName;
    }
}
string Client::getPersonalID() const {
    return personalID;
}
void Client::setPersonalID(const string& ID) {
    if (!ID.empty()) {
        personalID = ID;
    }
}
string Client::getInfo(){
    return "Client: "+firstName+" "+lastName+" "+"ID: "+personalID;
}
void Client::printDiagnostic(string message) {
    cout << message << " - Imię: " << firstName << ", Nazwisko: " << lastName << ", PESEL: " << personalID << endl;
}