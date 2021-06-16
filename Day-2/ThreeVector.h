#ifndef THREEVECTOR_H_
#define THREEVECTOR_H_

#include <iostream>

#ifndef DEBUG
#define MYDEBUG
#else
#define MYDEBUG \
  std::cerr << __DATE__ << " " << __TIME__ << " " \
            << __PRETTY_FUNCTION__  \
            << " <" << __FILE__ << ":" << __LINE__ << ">" << std::endl;
#endif

class ThreeVector {
  public:
    // constructor/copy constructor/destructor
    ThreeVector();
    ThreeVector(double x);
    ThreeVector(double x, double y);
    ThreeVector(double x, double y, double z);
    ThreeVector(const ThreeVector &v);
    ~ThreeVector();

  public:
    // assignment/comparison operators
    const ThreeVector& operator=(const ThreeVector &v);
    const ThreeVector operator+(const ThreeVector &v);
    const ThreeVector operator-(const ThreeVector &v);
    double operator*(const ThreeVector &v);
    ThreeVector operator*(double val);
    bool operator==(const ThreeVector &v) const;
    bool operator!=(const ThreeVector &v) const;

  public:
    // set/get methods and utilities
    double X() const;
    double Y() const;
    double Z() const;
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);

    // dot product
    double Dot(const ThreeVector &v) const;

    // cross product
    ThreeVector Cross(const ThreeVector &v) const;

  public:
    friend std::ostream& operator<<(std::ostream &os, const ThreeVector &v);
    friend std::istream& operator>>(std::istream &is, ThreeVector &v);
    friend ThreeVector operator*(double val, const ThreeVector &v);

  private:
    // data members
    double x_;
    double y_;
    double z_;
};

inline double ThreeVector::X() const {
  return x_;
}

inline double ThreeVector::Y() const {
  return y_;
}

inline double ThreeVector::Z() const {
  return z_;
}

inline void ThreeVector::SetX(double x) {
  x_ = x;
  return;
}

inline void ThreeVector::SetY(double y) {
  y_ = y;
  return;
}

inline void ThreeVector::SetZ(double z) {
  z_ = z;
  return;
}

inline double ThreeVector::Dot(const ThreeVector &v) const {
  return x_ * v.x_ + y_ * v.y_ + z_ * v.z_;
}

inline double ThreeVector::operator*(const ThreeVector &v) {
  return this->Dot(v);
}

inline ThreeVector ThreeVector::Cross(const ThreeVector &v) const {
  return ThreeVector(y_ * v.z_ - z_ * v.y_, z_ * v.x_ - x_ * v.z_, x_ * v.y_ - y_ * v.x_);
}

inline ThreeVector ThreeVector::operator*(double val) {
  MYDEBUG;
  return ThreeVector(this->x_ * val, this->y_ * val, this->z_ * val);
}

inline ThreeVector operator*(double val, const ThreeVector &v) {
  MYDEBUG;
  return ThreeVector(v.x_ * val, v.y_ * val, v.z_ * val);
}

#endif // THREEVECTOR_H_
