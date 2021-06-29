#include <iostream>
#include <cstdarg>
#include <vector>

// Variable Arguments
// #include <cstdarg>
// Macros:
// type va_arg(va_list ap, type);
// void va_copy(va_list dest, va_list src); // C99
// void va_end(va_list ap);
// void va_start(va_list ap, parmN);
// namespace std {
// Types:
//     va_list
// }
// int printf(const char *restrict format, ...);

int add_nums_va(int num, ...) {
  int result = 0;
  std::va_list args;
  va_start(args, num);
  for (int i = 0; i < num; i++) {
    result += va_arg(args, int);
  }
  va_end(args);
  return result;
}

int add_nums_vec(const std::vector<int>& numbers) {
  auto sum = 0;
  for (const auto& num : numbers) {
    sum += num;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  std::cout << add_nums_va(5, 1, 2, 3, 4, 5) << std::endl;
  std::cout << add_nums_vec({1, 2, 3, 4, 5}) << std::endl;
  return 0;
}
