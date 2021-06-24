#ifndef GIRAFFE_H_
#define GIRAFFE_H_

#include <iostream>
#include "Animal.h"

class Giraffe : public Animal {
  public:
    // constructor/copy constructor/destructor
    Giraffe();
    ~Giraffe();

  public:
    inline void Eat(food_t food) const {
      if (favorite_food_ == food) {
        std::cout << species_ << " ate " << food << ". Looks happy." << std::endl;
      } else {
        std::cout << species_ << " didn't eat " << food << ". Looks unhappy." << std::endl;
      }
    }
};

#endif // GIRAFFE_H_
