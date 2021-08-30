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
#include "DetectorConstruction.h"
#include "WaterPhantomSD.h"

#include "G4Material.hh"
#include "G4Element.hh"
#include "G4MaterialTable.hh"
#include "G4NistManager.hh"

#include "G4VSolid.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4PVReplica.hh"
#include "G4UserLimits.hh"

#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4GenericMessenger.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4ios.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
  : G4VUserDetectorConstruction(), fVisAttributes() {

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{
  for (auto visAttributes: fVisAttributes) {
    delete visAttributes;
  }  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Construct materials
  ConstructMaterials();
  auto air = G4Material::GetMaterial("G4_AIR");
  auto water = G4Material::GetMaterial("G4_WATER");

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  // geometries --------------------------------------------------------------
  // experimental hall (world volume)
  auto worldSolid 
    = new G4Box("worldBox",10./2. *m, 10./2.*m, 10./2.*m);
  auto worldLogical
    = new G4LogicalVolume(worldSolid,air,"worldLogical");
  auto worldPhysical
    = new G4PVPlacement(0,G4ThreeVector(),worldLogical,"worldPhysical",0,
                        false,0,checkOverlaps);

  G4double phantom_thickness = 1.0 * cm;
  auto phantomSolid = new G4Box("phantomBox", 40./2. * cm, 40./2. * cm, phantom_thickness/2.);
  auto phantomLogical = new G4LogicalVolume(phantomSolid, water, "phantomLogical");

   for (G4int z = 0; z < WaterPhantomSD::kNofCells; z++) {
     auto posz = 0 + z * 1.0*cm;
     new G4PVPlacement(0,                               //no rotation
                       G4ThreeVector(0., 0., posz), //at (0,0,0)
                       phantomLogical,                  //its logical volume
                       "phantomPhysical",               //its name
                       worldLogical,                    //its mother  volume
                       false,                           //no boolean operation
                       z,                               //copy number
                       checkOverlaps);                  //overlaps checking
   }

  // As a SD
   auto phantomSD = new WaterPhantomSD("/phantomSD");
   G4SDManager::GetSDMpointer()->AddNewDetector(phantomSD);
   phantomLogical->SetSensitiveDetector(phantomSD);

  // visualization attributes ------------------------------------------------
  auto visAttributes = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0));
  visAttributes->SetVisibility(false);
  worldLogical->SetVisAttributes(visAttributes);
  fVisAttributes.push_back(visAttributes);

  visAttributes = new G4VisAttributes(G4Colour(0.0,1.0,1.0));
  phantomLogical->SetVisAttributes(visAttributes);
  fVisAttributes.push_back(visAttributes);

  // return the world physical volume ----------------------------------------

  return worldPhysical;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


void DetectorConstruction::ConstructMaterials()
{
  auto nistManager = G4NistManager::Instance();

  // Air 
  nistManager->FindOrBuildMaterial("G4_AIR");
  // Water
  nistManager->FindOrBuildMaterial("G4_WATER");

  G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

