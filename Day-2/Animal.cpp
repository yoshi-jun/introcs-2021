#include "Animal.h"

Animal::Animal(const std::string &species, food_t favorite_food)
  : species_(species), favorite_food_(favorite_food) {
  MYDEBUG;
}

Animal::~Animal() {
  MYDEBUG;
}
