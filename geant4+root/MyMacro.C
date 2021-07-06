#include "TString.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TFile.h"

void MyMacro(const TString &ofile = "myfile.root") {
  TH1D* h = new TH1D("hist", "My Histogram", 100, -5, 5);
  h->FillRandom("gaus");

  Double_t x[] = {0, 1, 2, 3, 4};
  Double_t y[] = {0, 1, 8, 27, 64};
  TGraph* g = new TGraph(5, x, y);

  TCanvas* cv = new TCanvas("cv", "Canvas example", 800, 1200);
  cv->Divide(1, 2);
  cv->cd(1);
  h->Draw();
  cv->cd(2);
  g->Draw("ALP");

  TFile* f = new TFile(ofile.Data(), "RECREATE");
  h->Write();
  g->Write();
  f->Close();
}
