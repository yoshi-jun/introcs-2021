#ifndef CALCULATORT_H_
#define CALCULATORT_H_

template<class T>
class CalculatorT {
  public:
    // constructor/copy constructor/destructor
    CalculatorT();
    CalculatorT(const T &left, const T &right);
    CalculatorT(const CalculatorT& calc);
    ~CalculatorT();
  public:
    T Add();
    T Subtract();
  private:
    T left_;
    T right_;
};

#include "CalculatorT.tpp"

#endif // CALCULATORT_H_
