#include <vector>

#include "TFile.h"
#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TH2I.h"
#include "TCanvas.h"
#include "TStyle.h"

void WithTreeReader(const TString &ifile = "B5ntuple_e+.root") {
  TFile* f = new TFile(ifile.Data());
  TTreeReader reader("B5", f);

  TTreeReaderValue<Int_t> Dc1Hits(reader, "Dc1Hits");
  TTreeReaderValue<Int_t> Dc2Hits(reader, "Dc2Hits");
  TTreeReaderValue<Double_t> ECEnergy(reader, "ECEnergy");
  TTreeReaderValue<Double_t> HCEnergy(reader, "HCEnergy");
  TTreeReaderValue<Double_t> Time1(reader, "Time1");
  TTreeReaderValue<Double_t> Time2(reader, "Time2");
  TTreeReaderValue< std::vector<double> > ECEnergyVector(reader, "ECEnergyVector");
  TTreeReaderValue< std::vector<double> > HCEnergyVector(reader, "HCEnergyVector");

  // B5Constants.hh
  constexpr Int_t kNofEmColumns = 20;
  constexpr Int_t kNofEmRows = 4;
  constexpr Int_t kNofEmCells = kNofEmColumns * kNofEmRows;

  // B5DetectorConstruction.cc
  // auto emCalorimeterSolid
  //   = new G4Box("EMcalorimeterBox",1.5*m,30.*cm,15.*cm);
  TCanvas *cv = new TCanvas("cv", "EMCal (CsI)", 1200, 240);
  cv->ToggleEventStatus();
  cv->SetGrid();
  gStyle->SetGridStyle(kSolid);

  TH2I *h = new TH2I("hist", "EMCal (CsI)", kNofEmColumns, 0.0, static_cast<Double_t>(kNofEmColumns), kNofEmRows, 0, static_cast<Double_t>(kNofEmRows));
  h->SetNdivisions(kNofEmColumns, "X");
  h->SetNdivisions(kNofEmRows, "Y");
  h->Draw("COLZ");
  // Int_t i = 0;
  // cv->SaveAs(Form("cv-%.2d.gif", i++));
  Double_t SumECEnergy = 0.0;
  while (reader.Next()) {
    std::cout << "Dc1Hits=" << *Dc1Hits
              << "/Dc2Hits=" << *Dc2Hits
              << "/ECEnergy=" << *ECEnergy
              << "/HCEnergy=" << *HCEnergy
              << "/Time1=" << *Time1
              << "/Time2=" << *Time2
              << std::endl;
    SumECEnergy += *ECEnergy;
    for (auto copyNo = 0; copyNo < ECEnergyVector->size(); copyNo++) {
      // B5CellParameterisation.cc
      // for (auto copyNo = 0; copyNo < kNofEmCells; copyNo++) {
      //   auto column = copyNo / kNofEmRows;
      //   auto row = copyNo % kNofEmRows;
      //   fXCell[copyNo] = (column - 9) * 15. * cm - 7.5 * cm;
      //   fYCell[copyNo] = (row - 1) * 15 * cm - 7.5 * cm;
      // }
      auto column = copyNo / kNofEmRows;
      auto row = copyNo % kNofEmRows;
      auto edep = (*ECEnergyVector)[copyNo];
      auto x = static_cast<Double_t>(column);
      auto y = static_cast<Double_t>(row);
      h->Fill(x, y, edep);
    }
    cv->Modified();
    cv->Update();
    // cv->SaveAs(Form("cv-%.2d.gif", i++));
    gSystem->ProcessEvents();
  }
  std::cout << "h->GetSum()=" << h->GetSum() << std::endl;
  std::cout << "SumECEnergy=" << SumECEnergy << std::endl;
}
