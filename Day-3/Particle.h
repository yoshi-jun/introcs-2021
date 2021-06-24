#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <string>
#include "ThreeVector.h"

class Particle {
  public:
    // constructor/copy constructor/destructor
    Particle();
    Particle(const std::string &name, double mass, const ThreeVector &pos = ThreeVector(), const ThreeVector &mom = ThreeVector());
    Particle(const Particle& p);
    ~Particle();

  public:
    // assignment/comparison operators
    const Particle& operator=(const Particle& p);
    bool operator==(const Particle& p) const;
    bool operator!=(const Particle& p) const;

  public:
    // set/get methods and utilities
    inline const std::string& GetName() const {
      return name_;
    }
    inline double GetMass() const {
      return mass_;
    }
    inline const ThreeVector& GetPosition() const {
      return position_;
    }
    inline const ThreeVector& GetMomentum() const {
      return momentum_;
    }

  protected:
    // data members
    std::string name_;
    double mass_;
    ThreeVector position_;
    ThreeVector momentum_;
};

#endif // PARTICLE_H_
