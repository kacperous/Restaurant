#include "StorageContainer.h"


const ClientRepository &StorageContainer::getClientRepository() const {
    return clientRepository;
}

const ReservationRepository &StorageContainer::getReservationRepository() const {
    return reservationRepository;
}

const TableRepository &StorageContainer::getTableRepository() const {
    return tableRepository;
}

const RestaurantRepository &StorageContainer::getRestaurantRepository() const {
    return restaurantRepository;
}


void StorageContainer::initializeTestData() {
    AddressPtr address1= std::make_shared<Address>("Lodz","Jana Pawla","15");
    AddressPtr address2= std::make_shared<Address>("Lodz","al. Politechniki","2");
    AddressPtr address3= std::make_shared<Address>("Lodz","Niepodleglosci","17");
    AddressPtr address4= std::make_shared<Address>("Lodz","Batorego","4");
    AddressPtr address5= std::make_shared<Address>("Lodz","Pildudzkiego","45");
    AddressPtr address6= std::make_shared<Address>("Lodz","Wlokniarzy","1");

    TablePtr table1 = std::make_shared<Table>(1, 4, false, false);
    TablePtr table2 = std::make_shared<Table>(2, 6, false, true);
    TablePtr table3 = std::make_shared<Table>(1, 4, false, false);
    TablePtr table4 = std::make_shared<Table>(2, 6, false, true);

    Restaurant McDonald("McDonald",address1);
    Restaurant KFC("KFC",address2);
    McDonald.addTable(table1);
    McDonald.addTable(table2);
    KFC.addTable(table3);
    KFC.addTable(table4);

    ClientTypePtr regularClientType = std::make_shared<Default>();
    ClientTypePtr vipClientType = std::make_shared<VIP>();

    ClientPtr client1= std::make_shared<Client>(1,"Jan","Kowalski",123456789,address3,regularClientType);
    ClientPtr client2= std::make_shared<Client>(2,"Maciej","Kowalski",123456789,address4,vipClientType);
    ClientPtr client3= std::make_shared<Client>(3,"Jan","Michalak",123456789,address5,regularClientType);
    ClientPtr client4= std::make_shared<Client>(4,"Majkel","Usa",123456789,address3,vipClientType);

    std::tm date = {};
    date.tm_year = 2024 - 1900;
    date.tm_mon = 4;  // May (months are 0-based)
    date.tm_mday = 29;
    date.tm_hour = 18;
    date.tm_min = 30;
    date.tm_sec = 0;
    std::tm date2 = {};
    date2.tm_year = 2024 - 1900;
    date2.tm_mon = 4;  // May (months are 0-based)
    date2.tm_mday = 29;
    date2.tm_hour = 10;
    date2.tm_min = 30;
    date2.tm_sec = 0;

    ReservationPtr reservation1 = std::make_shared<Reservation>(1, date, client1, table1);
    ReservationPtr reservation2 = std::make_shared<Reservation>(2, date2, client3, table3);

    McDonald.addReservation(reservation1);
    KFC.addReservation(reservation2);
}