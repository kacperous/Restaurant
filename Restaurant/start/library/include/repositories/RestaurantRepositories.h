#ifndef RESTAURANTREPOSITORY_H
#define RESTAURANTREPOSITORY_H

#include <vector>
#include "../model/Restaurant.h"

class RestaurantRepository {
private:
    std::vector<Restaurant*> restaurants;
public:
    void addRestaurant(Restaurant* restaurant);
    void removeRestaurant(Restaurant* restaurant);
    std::vector<Restaurant*> findByName(const std::string& name);
};

#endif // RESTAURANTREPOSITORY_H
