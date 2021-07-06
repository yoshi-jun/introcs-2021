#include <iostream>
#include "G4RunManager.hh"
#ifdef HAVE_ROOT
#include "TROOT.h"
#include "TSystem.h"
#endif

int main() {
  G4RunManager* runManager = new G4RunManager();
  delete runManager;
#ifdef HAVE_ROOT
  std::cout << "gROOT->GetVersion()=" << gROOT->GetVersion() << std::endl;
  gSystem->Print();
#endif
  return 0;
}
