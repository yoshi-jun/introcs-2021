#include <iostream>

#include "Zoo.h"
#include "Tiger.h"
#include "Donkey.h"
#include "Giraffe.h"

int main() {
  Zoo* zoo = new Zoo("Wild Park");
  zoo->MoveIn(new Tiger());
  zoo->MoveIn(new Donkey());
  zoo->MoveIn(new Giraffe());
  zoo->Feed(straw);
  zoo->Feed(meat, 0);
  delete zoo;

  return 0;
}
