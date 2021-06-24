#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>
#include <string>

#ifndef DEBUG
#define MYDEBUG
#else
#define MYDEBUG \
  std::cerr << __DATE__ << " " << __TIME__ << " " \
            << __PRETTY_FUNCTION__                \
            << " <" << __FILE__ << ":" << __LINE__ << ">" << std::endl
#endif

typedef enum {
  meat,
  fruits,
  straw,
  fish,
  vegetable,
  leaf
} food_t;

class Animal {
  public:
    // constructor/copy constructor/destructor
    Animal(const std::string &species, food_t favorite_food);
    virtual ~Animal();

  public:
    // set/get methods and utilities
    inline const std::string &GetSpecies() const {
        return species_;
    }
    inline const food_t GetFavoriteFood() const {
        return favorite_food_;
    }

  public:
    virtual void Eat(food_t food) const = 0;

  protected:
    // data members
    std::string species_;
    food_t favorite_food_;
};

#endif // ANIMAL_H_
