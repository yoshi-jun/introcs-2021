// std::coutを使うために必要
#include <iostream>

int main() {
  // Signal型を定義します
  // Signal型の値は　red, blue, yellow, black　の４種類です
  typedef enum {
    green,
    yellow,
    red,
    black = -1
  } Signal;

  Signal go = green;
  Signal caution = yellow;
  Signal not_go = red;
  Signal not_work = black;
  
  // Signal signal = 1;
  // Signal signal = purple;

  std::cout << "go=" << go << std::endl;
  std::cout << "caution=" << caution << std::endl;
  std::cout << "not_go=" << not_go << std::endl;
  std::cout << "not_work=" << not_work << std::endl;
  std::cout << "sizeof(Signal)=" << sizeof(Signal) << " bytes" << std::endl;
  
  // すでにある型を別名で定義することもできます
  typedef double Weight;
  Weight my_weight = 123.456789;
  std::cout << "my_weight=" << my_weight << std::endl;
  std::cout << "sizeof(Weight)=" << sizeof(Weight) << " bytes" << std::endl;
  
  return 0;
}
