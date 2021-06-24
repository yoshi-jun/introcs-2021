#ifndef UNIT_H_
#define UNIT_H_

namespace unit {
  static const double mm = 1.0;
  static const double cm = 10.0 * mm;
  static const double m = 100.0 * cm;
  static const double um = 1.0e-6 * m;
  static const double nm = 1.0e-9 * m;
  static const double e_SI = 1.602176634e-19; // positron charge in coulomb
  static const double MeV = 1.;
  static const double eV = 1.e-6 * MeV;
  static const double keV = 1.e-3 * MeV;
  static const double GeV = 1.e+3 * MeV;
  static const double TeV = 1.e+6 * MeV;
  static const double joule = eV / e_SI; // joule = 6.24150 e+12 * MeV
}

#endif // UNIT_H_
