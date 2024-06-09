#include "repositories/RestaurantRepositories.h"

void RestaurantRepository::addRestaurant(Restaurant* restaurant) {
    restaurants.push_back(restaurant);
}

void RestaurantRepository::removeRestaurant(Restaurant* restaurant) {
    auto it = std::find(restaurants.begin(), restaurants.end(), restaurant);
    if (it != restaurants.end()) {
        restaurants.erase(it);
    }
}

std::vector<Restaurant*> RestaurantRepository::findByName(const std::string& name) {
    std::vector<Restaurant*> result;
    for (auto& restaurant : restaurants) {
        if (restaurant->getName() == name) {
            result.push_back(restaurant);
        }
    }
    return result;
}
