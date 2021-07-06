#include "MyMacro.C"

int main(int argc, char* argv[]) {
  auto ofile = "mymacro.root";
  if (argc == 2) {
    ofile = argv[1];
  }
  MyMacro(ofile);
  return 0;
}
