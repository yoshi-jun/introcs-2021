// std::coutを使うために必要
#include <iostream>
#include <limits.h>

// 「longは４バイトだ」という決めつけはしないこと
// sizeof 演算子でとってくる習慣をつけましょう
int main() {
  std::cout << "sizeof(int*)=" << sizeof(int*) << " bytes=" << sizeof(int *) * CHAR_BIT << " bits" << std::endl;

  std::cout << "sizeof(int)=" << sizeof(int) << " bytes=" << sizeof(int) * CHAR_BIT << " bits" << std::endl;
  std::cout << "sizeof(unsigned int)=" << sizeof(unsigned int) << " bytes=" << sizeof(unsigned int) * CHAR_BIT << " bits" << std::endl;

  std::cout << "sizeof(short)=" << sizeof(short) << " bytes=" << sizeof(short) * CHAR_BIT << " bits" << std::endl;
  std::cout << "sizeof(unsigned short)=" << sizeof(unsigned short) << " bytes=" << sizeof(unsigned short) * CHAR_BIT << " bits" << std::endl;

  std::cout << "sizeof(long)=" << sizeof(long) << " bytes=" << sizeof(long) * CHAR_BIT << " bits" << std::endl;
  std::cout << "sizeof(unsigned long)=" << sizeof(unsigned long) << " bytes=" << sizeof(unsigned long) * CHAR_BIT << " bits" << std::endl;

  std::cout << "sizeof(float)=" << sizeof(float) << " bytes=" << sizeof(float) * CHAR_BIT << " bits" << std::endl;
  std::cout << "sizeof(double)=" << sizeof(double) << " bytes=" << sizeof(double) * CHAR_BIT << " bits" << std::endl;
  std::cout << "sizeof(long double)=" << sizeof(long double) << " bytes=" << sizeof(long double) * CHAR_BIT << " bits" << std::endl;

  std::cout << "sizeof(char)=" << sizeof(char) << " byte=" << sizeof(char) * CHAR_BIT << " bits" << std::endl;
  std::cout << "sizeof(unsigned char)=" << sizeof(unsigned char) << " byte=" << sizeof(unsigned char) * CHAR_BIT << " bits" << std::endl;

  return 0;
}
