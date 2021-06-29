#include <iostream>

#include "CalculatorT.h"
#include "ThreeVector.h"

int main(int argc, char *argv[]) {
  CalculatorT<ThreeVector> calc(ThreeVector(1, 2, 3), ThreeVector(4, 5, 6));
  std::cout << calc.Add() << std::endl;
  std::cout << calc.Subtract() << std::endl;
  return 0;
}
