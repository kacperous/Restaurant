#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <limits>
#include <ctime>
#include "model/Restaurant.h"
#include "model/Reservation.h"
#include "model/Client.h"
#include "model/Adress.h"
#include "model/Table.h"
#include "model/ClientType.h"
#include "model/Default.h"
#include "model/VIP.h"
#include "managers/ReservationManager.h"
#include "managers/ClientManager.h"
#include "StorageContainer.h"
#include "managers/TableManager.h"
#include "repositories/TableRepositories.h"

using namespace std;

void showMenu() {
    cout << "1. Add Client" << endl;
    cout << "2. Add Table" << endl;
    cout << "3. Add Reservation" << endl;
    cout << "4. Show Restaurant Info" << endl;
    cout << "5. Show Reservations" << endl;
    cout << "6. Show Client Reservations" << endl;
    cout << "7. Check Client" << endl;
    cout << "8. Remove Table" << endl;
    cout << "9. Remove Client" << endl;
    cout << "10. Exit" << endl;
}
void saveState(const vector<ClientPtr>& clients, const vector<TablePtr>& tables, const vector<ReservationPtr>& reservations) {
    ofstream outFile("state.txt");
    if (!outFile.is_open()) {
        cerr << "Unable to open file for saving state." << endl;
        return;
    }

    outFile << clients.size() << endl;
    for (const auto& client : clients) {
        outFile << client->getPersonalId() << " "
                << client->getFirstName() << " "
                << client->getLastName() << " "
                << client->getPhoneNumber() << " "
                << (dynamic_pointer_cast<VIP>(client->getClientType()) ? "VIP" : "Default") << endl;
    }

    outFile << tables.size() << endl;
    for (const auto& table : tables) {
        outFile << table->getTableId() << " "
                << table->getTableSize() << " "
                << table->getIsReserved() << " "
                << table->getIsVipTable() << endl;
    }

    outFile << reservations.size() << endl;
    for (const auto& reservation : reservations) {
        auto date = reservation->getDate();
        outFile << reservation->getReservationId() << " "
                << reservation->getClient()->getPersonalId() << " "
                << reservation->getTable()->getTableId() << " "
                << (date.tm_year + 1900) << " "
                << (date.tm_mon + 1) << " "
                << date.tm_mday << " "
                << date.tm_hour << " "
                << date.tm_min << endl;
    }

    outFile.close();
}
void loadState(vector<ClientPtr>& clients, vector<TablePtr>& tables, vector<ReservationPtr>& reservations, Restaurant& restaurant, ClientRepository& clientRepository) {
    ifstream inFile("state.txt");
    if (!inFile.is_open()) {
        cerr << "Unable to open file for loading state." << endl;
        return;
    }

    int numClients, numTables, numReservations;
    inFile >> numClients;
    clients.clear();
    for (int i = 0; i < numClients; ++i) {
        int id, phoneNumber;
        string firstName, lastName, clientTypeStr;
        inFile >> id >> firstName >> lastName >> phoneNumber >> clientTypeStr;
        ClientTypePtr clientType = (clientTypeStr == "VIP") ? std::static_pointer_cast<ClientType>(std::make_shared<VIP>()) : std::static_pointer_cast<ClientType>(std::make_shared<Default>());
        ClientPtr client = std::make_shared<Client>(id, firstName, lastName, phoneNumber, restaurant.getAddress(), clientType);
        clients.push_back(client);
        clientRepository.addClient(client);
    }

    inFile >> numTables;
    tables.clear();
    for (int i = 0; i < numTables; ++i) {
        int id, size;
        bool isReserved, isVIP;
        inFile >> id >> size >> isReserved >> isVIP;
        TablePtr table = std::make_shared<Table>(id, size, isReserved, isVIP);
        tables.push_back(table);
        restaurant.addTable(table);
    }

    inFile >> numReservations;
    reservations.clear();
    for (int i = 0; i < numReservations; ++i) {
        int id, clientId, tableId, year, month, day, hour, minute;
        inFile >> id >> clientId >> tableId >> year >> month >> day >> hour >> minute;

        ClientPtr client = nullptr;
        for (auto& c : clients) {
            if (c->getPersonalId() == clientId) {
                client = c;
                break;
            }
        }

        TablePtr table = nullptr;
        for (auto& t : tables) {
            if (t->getTableId() == tableId) {
                table = t;
                break;
            }
        }

        std::tm date = {};
        date.tm_year = year - 1900;
        date.tm_mon = month - 1;
        date.tm_mday = day;
        date.tm_hour = hour;
        date.tm_min = minute;
        date.tm_sec = 0;

        ReservationPtr reservation = std::make_shared<Reservation>(id, date, client, table);
        reservations.push_back(reservation);
        restaurant.addReservation(reservation);
    }

    inFile.close();
}


int main() {
    // Create Address
    AddressPtr address = std::make_shared<Address>("City", "Main St", "123");

    // Create Client Types
    ClientTypePtr regularClientType = std::make_shared<Default>();
    ClientTypePtr vipClientType = std::make_shared<VIP>();

    // Create Restaurant
    Restaurant restaurant("Good Eats", address);

    StorageContainer storageContainer;
    // Client and Reservation Managers
    ClientManager clientManager;
    ClientRepository clientRepository = storageContainer.getClientRepository();
    TableManager tableManager;
    TableRepository tableRepository = storageContainer.getTableRepository();
    ReservationManager reservationManager;
    ReservationRepository reservationRepository = storageContainer.getReservationRepository();

    vector<ClientPtr> clients;
    vector<TablePtr> tables;
    vector<ReservationPtr> reservations;

    // Load state from file
    loadState(clients, tables, reservations, restaurant, clientRepository);

    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input, please enter a number between 1 and 10." << endl;
            continue;
        }

        switch (choice) {
            case 1: {
                // Add Client
                int id;
                string firstName, lastName;
                int phoneNumber;
                int clientTypeChoice;
                cout << "Enter Client ID: ";
                cin >> id;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter Phone Number: ";
                cin >> phoneNumber;
                cout << "Choose Client Type (1- Regular, 2- VIP): ";
                cin >> clientTypeChoice;
                ClientTypePtr clientType = (clientTypeChoice == 1) ? regularClientType : vipClientType;
                ClientPtr client = std::make_shared<Client>(id, firstName, lastName, phoneNumber, address, clientType);
                clientRepository.addClient(client);
                clients.push_back(client);
                cout << "Client added successfully." << endl;
                break;
            }
            case 2: {
                // Create Table
                int id, size;
                bool isReserved, isVIP;
                cout << "Enter Table ID: ";
                cin >> id;
                cout << "Enter Table Size: ";
                cin >> size;
                cout << "Is Table Reserved? (0- No, 1- Yes): ";
                cin >> isReserved;
                cout << "Is Table for VIP? (0- No, 1- Yes): ";
                cin >> isVIP;
                TablePtr table = std::make_shared<Table>(id, size, isReserved, isVIP);
                tables.push_back(table);
                restaurant.addTable(table);
                cout << "Table added successfully." << endl;
                break;
            }
            case 3: {
                // Add Reservation
                int id, clientId, tableId, year, month, day, hour, minute;
                cout << "Enter Reservation ID: ";
                cin >> id;
                cout << "Enter Client ID: ";
                cin >> clientId;
                cout << "Enter Table ID: ";
                cin >> tableId;
                cout << "Enter Reservation Date (YYYY MM DD HH MM): ";
                cin >> year >> month >> day >> hour >> minute;

                // Find Client
                ClientPtr client = nullptr;
                for (auto& c : clients) {
                    if (c->getPersonalId() == clientId) {
                        client = c;
                        break;
                    }
                }
                if (!client) {
                    cout << "Client not found." << endl;
                    break;
                }

                // Find Table
                TablePtr table = nullptr;
                for (auto& t : tables) {
                    if (t->getTableId() == tableId) {
                        table = t;
                        break;
                    }
                }
                if (!table) {
                    cout << "Table not found." << endl;
                    break;
                }

                std::tm date = {};
                date.tm_year = year - 1900;
                date.tm_mon = month - 1;
                date.tm_mday = day;
                date.tm_hour = hour;
                date.tm_min = minute;
                date.tm_sec = 0;

                ReservationPtr reservation = std::make_shared<Reservation>(id, date, client, table);
                reservations.push_back(reservation);
                restaurant.addReservation(reservation);
                cout << "Reservation added successfully." << endl;
                break;
            }
            case 4: {
                // Show Restaurant Info
                cout << restaurant.getInfo() << endl;
                restaurant.showTables();
                break;
            }
            case 5: {
                // Show Reservations
                restaurant.showReservations();
                break;
            }
            case 6: {
                // Show Client Reservations
                int clientId;
                cout << "Enter Client ID: ";
                cin >> clientId;

                ClientPtr client = nullptr;
                for (auto& c : clients) {
                    if (c->getPersonalId() == clientId) {
                        client = c;
                        break;
                    }
                }
                if (!client) {
                    cout << "Client not found." << endl;
                    break;
                }

                auto clientReservations = clientManager.getClientReservations(client, reservations);
                cout << "Reservations for client:" << endl;
                for (auto& res : clientReservations) {
                    cout << res->getInfo() << endl;
                }
                break;
            }
            case 7: {
                // Check Client
                int clientId;
                cout << "Enter Client ID: ";
                cin >> clientId;

                ClientPtr client = nullptr;
                for (auto& c : clients) {
                    if (c->getPersonalId() == clientId) {
                        client = c;
                        break;
                    }
                }
                if (!client) {
                    cout << "Client not found." << endl;
                    break;
                }

                bool clientExists = clientManager.checkClient(client);
                cout << "Client exists: " << clientExists << endl;
                break;
            }
            case 8: {
                // Remove Table
                int tableId;
                cout << "Enter Table ID to remove: ";
                cin >> tableId;

                TablePtr table = nullptr;
                for (auto& t : tables) {
                    if (t->getTableId() == tableId) {
                        table = t;
                        break;
                    }
                }
                if (!table) {
                    cout << "Table not found." << endl;
                    break;
                }

                restaurant.removeTable(table);
                tables.erase(remove(tables.begin(), tables.end(), table), tables.end());
                cout << "Table removed successfully." << endl;
                break;
            }
            case 9: {
                // Remove Client
                int clientId;
                cout << "Enter Client ID to remove: ";
                cin >> clientId;

                ClientPtr client = nullptr;
                for (auto& c : clients) {
                    if (c->getPersonalId() == clientId) {
                        client = c;
                        break;
                    }
                }
                if (!client) {
                    cout << "Client not found." << endl;
                    break;
                }

                clientRepository.removeClient(client);
                clients.erase(remove(clients.begin(), clients.end(), client), clients.end());
                cout << "Client removed successfully." << endl;
                break;
            }
            case 10: {
                // Exit
                cout << "Exiting..." << endl;

                // Save state to file
                saveState(clients, tables, reservations);

                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                break;
            }
        }
    } while (choice != 10);

    return 0;
}
