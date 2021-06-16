#include <iostream>
#include <fstream>
#include "ThreeVector.h"

int main(int argc, char* argv[]) {
  const char* filename = "file.out";

  std::ofstream ofs(filename);
  for (int i = 0; i < 100; i++) {
    ofs << ThreeVector(i, i*i, i*i*i) << std::endl;
  }
  ofs.close();

  std::ifstream ifs(filename);
  ThreeVector v;
  while (ifs >> v) {
    std::cout << v << std::endl;
  }
  ifs.close();

  return 0;
}
