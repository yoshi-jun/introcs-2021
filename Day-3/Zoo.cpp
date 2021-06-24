#include "Zoo.h"

Zoo::Zoo(const std::string &zoo_name, int number_of_cages)
  : zoo_name_(zoo_name),
    number_of_cages_(number_of_cages),
    number_of_animals_(0),
    animals_(nullptr) {
  animals_ = new Animal*[number_of_cages_];
}

Zoo::~Zoo() {
  MYDEBUG;
  for (int i = 0; i < number_of_animals_; i++) {
    std::cout << "Deleting " << animals_[i]->GetSpecies() << " in the cage: " << i << std::endl;
    delete animals_[i];
  }
  delete [] animals_;
}

void Zoo::MoveIn(Animal *animal) {
  if (number_of_animals_ < number_of_cages_) {
    animals_[number_of_animals_] = animal;
    number_of_animals_++;
  }
}

void Zoo::Feed(food_t food, int id) {
  MYDEBUG;
  if (id < 0) {
    for (int i = 0; i < number_of_animals_; i++) {
      animals_[i]->Eat(food);
    }
  } else if (id < number_of_animals_) {
    animals_[id]->Eat(food);
  }
}
