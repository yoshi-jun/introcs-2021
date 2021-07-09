#include "G4RunManagerFactory.hh"
#ifdef HAVE_ROOT
#include "TROOT.h"
#include "TSystem.h"
#endif

int main() {
  auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);
#ifdef HAVE_ROOT
  G4cout << "gROOT->GetVersion()=" << gROOT->GetVersion() << G4endl;
  gSystem->Print();
#endif
  delete runManager;
  return 0;
}
