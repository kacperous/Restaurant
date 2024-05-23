#ifndef RESTAURANT_TYPEDEFS_H
#define RESTAURANT_TYPEDEFS_H
#include <memory>
class Client;
class ClientType;
class Address;
class Table;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Table> TablePtr;


#endif //RESTAURANT_TYPEDEFS_H
