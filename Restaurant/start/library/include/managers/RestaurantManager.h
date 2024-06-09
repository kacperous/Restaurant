#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include <vector>
#include "model/Restaurant.h"
#include "repositories/RestaurantRepositories.h"

class RestaurantManager {
private:
    RestaurantRepository restaurantRepository;
public:
    std::vector<Restaurant*> getRestaurants();
    std::vector<Restaurant*> findByName(const std::string& name);
    void addRestaurant(Restaurant* restaurant);
    void removeRestaurant(Restaurant* restaurant);
    int countRestaurants();
};

#endif // RESTAURANTMANAGER_H
