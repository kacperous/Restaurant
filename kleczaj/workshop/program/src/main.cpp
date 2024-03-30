#include <iostream>
#include "model/Client.h"
#include "model/Adress.h"
using namespace std;
int main(){
    Adress *a1= new Adress("lodz","piotrkowska","15");
    Adress *a2= new Adress("lodddddddz","piotrsssssskowska","1522222");
    Client c1("Jan","Kowalski","1",a1);
    Client *c2= new Client("Wojtek","Szczesny","2",a2);
    cout<<c1.getInfo()<<endl;
    cout<<c2->getInfo()<<endl;
    cout<<a1->getInfo()<<endl;
    cout<<a2->getInfo()<<endl;
    delete c2;
    delete a1;
    delete a2;
	return 0;
}
