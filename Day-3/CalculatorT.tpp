#include "CalculatorT.h"

template<class T>
CalculatorT<T>::CalculatorT()
  : left_(), right_() {
}

template<class T>
CalculatorT<T>::CalculatorT(const T& left, const T& right)
  : left_(left), right_(right) {
}

template<class T>
inline CalculatorT<T>::CalculatorT(const CalculatorT& calc)
  : left_(calc.left_), right_(calc.right_) {
}

template<class T>
CalculatorT<T>::~CalculatorT() {
}

template<class T>
inline T CalculatorT<T>::Add() {
  return left_ + right_;
}

template<class T>
inline T CalculatorT<T>::Subtract() {
  return left_ - right_;
}
