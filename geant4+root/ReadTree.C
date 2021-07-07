#include <iostream>
#include <vector>

#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"

void ReadTree(const TString& ifile = "B5ntuple_e+.root") {
  auto f = new TFile(ifile.Data());
  auto t = f->Get<TTree>("B5");

  Int_t Dc1Hits, Dc2Hits;
  Double_t ECEnergy, HCEnergy, Time1, Time2;
  TBranch *brECEV = nullptr;
  TBranch *brHCEV = nullptr;
  std::vector<double>* ECEnergyVector = nullptr;
  std::vector<double>* HCEnergyVector = nullptr;
  t->SetBranchAddress("Dc1Hits", &Dc1Hits);
  t->SetBranchAddress("Dc2Hits", &Dc2Hits);
  t->SetBranchAddress("ECEnergy", &ECEnergy);
  t->SetBranchAddress("HCEnergy", &HCEnergy);
  t->SetBranchAddress("Time1", &Time1);
  t->SetBranchAddress("Time2", &Time2);
  t->SetBranchAddress("ECEnergyVector", &ECEnergyVector, &brECEV);
  t->SetBranchAddress("HCEnergyVector", &HCEnergyVector, &brHCEV);

  for (auto i = 0; i < t->GetEntries(); i++) {
    t->GetEntry(i);
    std::cout << "Dc1Hits=" << Dc1Hits
              << "/Dc2Hits=" << Dc2Hits
              << "/ECEnergy=" << ECEnergy
              << "/HCEnergy=" << HCEnergy
              << "/Time1=" << Time1
              << "/Time2=" << Time2 << std::endl;

    Long64_t tentry = t->LoadTree(i);
    brECEV->GetEntry(tentry);
    for (std::size_t eci = 0; eci < ECEnergyVector->size(); eci++) {
      std::cout << "ECEnergyVector[" << eci << "]=" << (*ECEnergyVector)[eci] << std::endl;
    }
    brHCEV->GetEntry(tentry);
    for (std::size_t hci = 0; hci < HCEnergyVector->size(); hci++) {
      std::cout << "HCEnergyVector[" << hci << "]=" << (*HCEnergyVector)[hci] << std::endl;
    }
  }
}
