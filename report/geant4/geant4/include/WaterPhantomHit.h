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

#ifndef WaterWaterPhantomHit_h
#define WaterWaterPhantomHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"

/// Water Phantom Hit
///
/// It records:
/// - the cell ID
/// - the energy deposit 

class WaterPhantomHit : public G4VHit
{
public:
  WaterPhantomHit();
  WaterPhantomHit(G4int cellID);
  WaterPhantomHit(const WaterPhantomHit &right);
  virtual ~WaterPhantomHit();

  const WaterPhantomHit &operator=(const WaterPhantomHit &right);
  G4bool operator==(const WaterPhantomHit &right) const;

  inline void *operator new(size_t);
  inline void operator delete(void *aHit);

  virtual void Draw();
  virtual void Print();

  void SetCellID(G4int z) { fCellID = z; }
  G4int GetCellID() const { return fCellID; }

  void SetEdep(G4double de) { fEdep = de; }
  void AddEdep(G4double de) { fEdep += de; }
  G4double GetEdep() const { return fEdep; }

  //add 

  void SetEdep_hit(G4double de){Edep_hit.push_back(de);}
  G4double GetEdep_hit(int de) const {return Edep_hit[de];}
  int GetLength() const {return Edep_hit.size();}

private:
  G4int fCellID;
  G4double fEdep;

  //add 

  std::vector<G4double> Edep_hit;
};

using WaterPhantomHitsCollection = G4THitsCollection<WaterPhantomHit>;

extern G4ThreadLocal G4Allocator<WaterPhantomHit>* WaterPhantomHitAllocator;

inline void* WaterPhantomHit::operator new(size_t)
{
  if (!WaterPhantomHitAllocator) {
       WaterPhantomHitAllocator = new G4Allocator<WaterPhantomHit>;
  }
  return (void*)WaterPhantomHitAllocator->MallocSingle();
}

inline void WaterPhantomHit::operator delete(void* aHit)
{
  WaterPhantomHitAllocator->FreeSingle((WaterPhantomHit*) aHit);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
