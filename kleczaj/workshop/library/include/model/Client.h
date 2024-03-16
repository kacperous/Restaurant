#include <iostream>
using namespace std;
class Client{
private:
    string firstName;
    string lastName;
    int personalID;

public:
    void getInfo(string name,string lastname,int ID){
        name=firstName;
        lastname=lastName;
        ID=personalID;
    }
};