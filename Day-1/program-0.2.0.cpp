#include <iostream>

// sleepを使うために必要
#ifndef WIN32
#include <unistd.h>
#else
#include <stdlib.h>
#define sleep(sec) _sleep(sec*1000)
#endif

const char* VERSION = "0.2.0";
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
  sleep(1);
  std::cout << "." << std::flush;
  sleep(1);
  std::cout << "." << std::flush;
  sleep(1);
  std::cout << "." << std::flush;
  sleep(1);
  std::cout << " DONE!" << std::endl;
  return;
}
