// $Id: main.cc,v 1.3 2004/11/28 12:48:37 iwai Exp $
// inc01.h に依存している
#include "make-inc1.h"

#ifndef WIN32
extern "C++" {
#endif
  // func01.o(関数の実部分)に依存している
  void make_func1();
  // func02.o(関数の実部分)に依存している
  void make_func2();
#ifndef WIN32
}
#endif

int main() {
  make_func1();
  make_func2();
  return 0;
}
