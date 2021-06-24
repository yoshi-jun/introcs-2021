#ifndef DONKEY_H_
#define DONKEY_H_

#include <iostream>
#include "Animal.h"

class Donkey : public Animal {
  public:
    // constructor/copy constructor/destructor
    Donkey();
    ~Donkey();

  public:
    inline void Eat(food_t food) const {
      if (favorite_food_ == food) {
        std::cout << species_ << " ate " << food << ". Looks happy." << std::endl;
      } else {
        std::cout << species_ << " didn't eat " << food << ". Looks unhappy." << std::endl;
      }
    }
};

#endif // DONKEY_H_
