#include <iostream>
#include "model/Client.h"
using namespace std;
int main(){
    Client c1("Jan","Kowalski","1");
    Client *c2= new Client("Wojtek","Szczesny","2");
    cout<<c1.getInfo()<<endl;
    cout<<c2->getInfo()<<endl;
    delete c2;
	return 0;
}
