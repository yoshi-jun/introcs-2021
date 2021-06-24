#ifndef TIGER_H_
#define TIGER_H_

#include <iostream>
#include "Animal.h"

class Tiger : public Animal {
  public:
    // constructor/copy constructor/destructor
    Tiger();
    ~Tiger();

  public:
    inline void Eat(food_t food) const {
      if (favorite_food_ == food) {
        std::cout << species_ << " ate " << food << ". Looks happy." << std::endl;
      } else {
        std::cout << species_ << " didn't eat " << food << ". Looks unhappy." << std::endl;
      }
    }
};

#endif // TIGER_H_
