#include "Particle.h"

Particle::Particle()
  : name_("pseudo"), mass_(0.0), position_(ThreeVector()), momentum_(ThreeVector()) {
}

Particle::Particle(const std::string &name, double mass, const ThreeVector &pos, const ThreeVector &mom)
  : name_(name), mass_(mass), position_(pos), momentum_(mom) {
}

Particle::~Particle() {

}

Particle::Particle(const Particle &p)
  : name_(p.name_), mass_(p.mass_), position_(p.position_), momentum_(p.momentum_) {
}

const Particle& Particle::operator=(const Particle& p) {
  name_ = p.name_;
  mass_ = p.mass_;
  position_ = p.position_;
  momentum_ = p.momentum_;
  return *this;
}

bool Particle::operator==(const Particle& p) const {
  return (name_ == p.name_);
}

bool Particle::operator!=(const Particle& p) const {
  return (name_ != p.name_);
}
