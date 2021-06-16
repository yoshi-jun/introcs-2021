// std::coutを使うために必要
#include <iostream>

// 各変数型の最大値と最小値が定義されています
#include <limits.h>
#include <float.h>

int main() {
  // limits.h より
  std::cout << "(signed) int: " << INT_MIN << "~" << INT_MAX << std::endl;
  std::cout << "unsigned int: " << 0 << "~" << UINT_MAX << std::endl;
  std::cout << "(signed) short: " << SHRT_MIN << "~" << SHRT_MAX << std::endl;
  std::cout << "unsigned short: " << 0 << "~" << USHRT_MAX << std::endl;
  std::cout << "(signed) long: " << LONG_MIN << "~" << LONG_MAX << std::endl;
  std::cout << "unsigned long: " << 0 << "~" << ULONG_MAX << std::endl;

  // float.h より
  std::cout << "float: " << FLT_MIN << "~" << FLT_MAX << std::endl;
  std::cout << "double: " << DBL_MIN << "~" << DBL_MAX << std::endl;
  std::cout << "long double: " << LDBL_MIN << "~" << LDBL_MAX << std::endl;

  // limits.h より
  std::cout << "(signed) char: " << CHAR_MIN << "~" << CHAR_MAX << std::endl;
  std::cout << "unsigned char: " << 0 << "~" << UCHAR_MAX << std::endl;

  return 0;
}
