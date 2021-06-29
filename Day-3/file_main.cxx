#include <iostream>
#include <string>
#include "File.h"
#include <limits.h>

int main(int argc, char* argv[]) {
  if (argc == 3) {
    const std::string ifile = argv[1];
    const std::string ofile = argv[2];
    File f;
    try {
      f.Copy(ifile, ofile);
    } catch (std::exception& e) {
      std::cerr << "e.what()=" << e.what() << std::endl;
    } catch (...) {
      std::cerr << "Caught a default exception." << std::endl;
      std::terminate();
    }
  }
  return 0;
}
