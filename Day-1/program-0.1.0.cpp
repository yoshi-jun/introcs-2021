#include <iostream>

const char* VERSION = "0.1.0";
void process();

int main()
{
  // プログラムバージョンの出力
  std::cout << "VERSION NUMBER: " << VERSION << std::endl;
  // なんらかの処理
  process();
  return 0;
}

void process()
{
  std::cout << "PROCESS START IN FUNCTION" << std::flush;
  std::cout << "." << std::flush;
  std::cout << "." << std::flush;
  std::cout << "." << std::flush;
  std::cout << " DONE!" << std::endl;
  return;
}
