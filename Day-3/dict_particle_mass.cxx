#include <iostream>
#include <string>
#include <map>
#include "unit.h"

using namespace unit;

int main(int argc, char* argv[]) {
  std::map<std::string, double> dict_particle_mass;
  dict_particle_mass["electron"] = 0.510998950 * MeV;
  dict_particle_mass["positron"] = 0.510998946 * MeV;
  dict_particle_mass["proton"] = 938.272088 * MeV;
  dict_particle_mass["neutron"] = 939.565420 * MeV;

#if CXXSTD == 11
  // C++11
  for (auto itr : dict_particle_mass) {
    std::cout << "[C++11] " << itr.first << ": " << itr.second / MeV << " MeV" << std::endl;
  }
#elif CXXSTD == 17
  // C++17
  for (auto [name, mass] : dict_particle_mass) {
    std::cout << "[C++17] " << name << ": " << mass / MeV << " MeV" << std::endl;
  }
#else
  // C++98
  for (std::map<std::string, double>::iterator itr = dict_particle_mass.begin(); itr != dict_particle_mass.end(); itr++) {
    std::cout << "[C++98] " << itr->first << ": " << itr->second / MeV << " MeV" << std::endl;
  }
#endif

  return 0;
}
