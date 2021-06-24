#ifndef ZOO_H_
#define ZOO_H_

#include <string>

#include "Animal.h"

class Animal;

class Zoo {
  public:
    // constructor/copy constructor/destructor
    Zoo(const std::string &zoo_name, int number_of_cages = 10);
    ~Zoo();

  public:
    // set/get methods and utilities
    void MoveIn(Animal* animal);
    void Feed(food_t food, int id = -1);

  private:
    // data members
    std::string zoo_name_;
    int number_of_cages_;
    int number_of_animals_;
    Animal** animals_;
};

#endif // ZOO_H_
