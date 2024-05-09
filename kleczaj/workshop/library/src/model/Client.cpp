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
const AdressPtr& Client::getAdress() const {
    return adress;
}
void Client::setAdress(AdressPtr adr) {
    if(adr!=nullptr){
        adress=adr;
    }
}
void Client::addRent(RentPtr newRent) {
    currentRents.push_back(newRent);
}
void Client::removeRent(){
    currentRents.erase(currentRents.begin());
}
const vector<RentPtr> &Client::getCurrentRents() const {
    return currentRents;
}
int Client::getMaxVehicles() const {
    return clientType->getMaxVehicles();
}
double Client::applyDiscount(double price) const {
    return clientType->applyDiscount(price);
}
void Client::setClientType(ClientType *newClientType) {
    clientType=newClientType;
}
string Client::toString() const {
    return firstName+" "+lastName+" "+personalID+"\n";
}