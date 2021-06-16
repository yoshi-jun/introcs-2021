#include <iostream>

#include "ThreeVector.h"

ThreeVector::ThreeVector()
  : x_(0.0), y_(0.0), z_(0.0) {
  MYDEBUG;
}

ThreeVector::ThreeVector(double x)
  : x_(x), y_(0.0), z_(0.0) {
  MYDEBUG;
}

ThreeVector::ThreeVector(double x, double y)
  : x_(x), y_(y), z_(0.0) {
  MYDEBUG;
}

ThreeVector::ThreeVector(double x, double y, double z)
  : x_(x), y_(y), z_(z) {
  MYDEBUG;
}

ThreeVector::ThreeVector(const ThreeVector &v)
  : x_(v.x_), y_(v.y_), z_(v.z_) {
  MYDEBUG;
}

ThreeVector::~ThreeVector() {
  MYDEBUG;
}

const ThreeVector& ThreeVector::operator=(const ThreeVector &v) {
  MYDEBUG;
  this->x_ = v.x_;
  this->y_ = v.y_;
  this->z_ = v.z_;
  return *this;
}

bool ThreeVector::operator==(const ThreeVector &v) const {
  MYDEBUG;
  if (this->x_ == v.x_ && this->y_ == v.y_ && this->z_ == v.z_) {
    return true;
  } else {
    return false;
  }
}

bool ThreeVector::operator!=(const ThreeVector &v) const {
  MYDEBUG;
  if (this->x_ != v.x_ || this->y_ != v.y_ || this->z_ != v.z_) {
    return true;
  } else {
    return false;
  }
}

const ThreeVector ThreeVector::operator+(const ThreeVector &v) {
  MYDEBUG;
  return ThreeVector(this->x_ + v.x_, this->y_ + v.y_, this->z_ + v.z_);
}

const ThreeVector ThreeVector::operator-(const ThreeVector &v) {
  MYDEBUG;
  return ThreeVector(this->x_ - v.x_, this->y_ - v.y_, this->z_ - v.z_);
}

std::ostream& operator<<(std::ostream &os, const ThreeVector &v) {
  MYDEBUG;
  return os << v.x_ << ' ' << v.y_ << ' ' << v.z_;
}

std::istream& operator>>(std::istream &is, ThreeVector &v) {
  MYDEBUG;
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
  is >> x;
  is >> y;
  is >> z;
  v.x_ = x;
  v.y_ = y;
  v.z_ = z;
  return is;
}
