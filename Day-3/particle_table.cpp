#include <iostream>
#include <vector>
#include "Particle.h"
#include "unit.h"

using namespace unit;

int main(int argc, char* argv[]) {
  std::vector<Particle> particle_table;
  particle_table.push_back(Particle("electron", 0.510998950 * MeV));
  particle_table.push_back(Particle("positron", 0.510998946 * MeV));
  particle_table.push_back(Particle("proton", 938.272088 * MeV));
  particle_table.push_back(Particle("neutron", 939.565420 * MeV));
  for (std::size_t i = 0; i < particle_table.size(); i++) {
    std::cout << particle_table[i].GetName() << ": " << particle_table[i].GetMass() / GeV << " GeV" << std::endl;
  }
  return 0;
}
