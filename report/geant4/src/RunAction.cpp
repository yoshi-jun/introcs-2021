//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//

#include "RunAction.h"
#include "EventAction.h"

#include "G4Run.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericAnalysisManager.hh"

using G4AnalysisManager = G4GenericAnalysisManager;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction(EventAction* eventAction)
 : G4UserRunAction(),
   fEventAction(eventAction)
{ 
  // Create the generic analysis manager
  // The choice of analysis technology is done according to the file extension
  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetActivation(true);
  analysisManager->SetVerboseLevel(1);

  // Default settings
  analysisManager->SetNtupleMerging(true);
     // Note: merging ntuples is available only with Root output
  analysisManager->SetFileName("/home/test-man/Work/geant4/tutorial/homework_introcs/introcs-2021/report/geant4/build/test.root");
     // If the filename extension is not provided, the default file type (root)
     // will be used for all files specified without extension.
  // analysisManager->SetDefaultFileType("xml");
     // The default file type (root) can be redefined by the user.

  // Book histograms, ntuple
  
  // Creating ntuple
  if ( fEventAction ) {
    analysisManager->CreateNtuple("IntroCS", "Hits");
    // analysisManager                               // column Id = 6
    //analysisManager->CreateNtupleDColumn("Edep", fEventAction->GetEdep()); // column Id = 0
    analysisManager->CreateNtupleDColumn("Edeps");
    analysisManager->FinishNtuple();
  }

  // Set ntuple output file
  //analysisManager->SetNtupleFileName(0, "tree");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{
  // delete G4AnalysisManager::Instance();  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* /*run*/)
{ 
  //inform the runManager to save random number seed
  //G4RunManager::GetRunManager()->SetRandomNumberStore(true);
  
  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // Open an output file 
  // The default file name is set in RunAction::RunAction(),
  // it can be overwritten in a macro
  analysisManager->OpenFile();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* /*run*/)
{
  // save histograms & ntuple
  //
  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  analysisManager->CloseFile();

  //G4cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~called Fclose~~~~~~~~~~~~~~~~"<<G4endl;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
