#include <iostream>

// デバッグ用のマクロを定義する
#ifndef WIN32
#define MYDEBUG(msg) \
  std::cout << __DATE__ << " " << __TIME__ \
            << " [" << msg << "]"  \
            << " in \"" << __PRETTY_FUNCTION__ \
            << "\" at " << __FILE__ \
            << " line " << __LINE__ << "." << std::endl;
#else
#define MYDEBUG(msg) \
  std::cout << __DATE__ << " " << __TIME__ \
            << " [" << msg << "]"  \
            << "\" at " << __FILE__ \
            << " line " << __LINE__ << "." << std::endl;
#endif

int main()
{
#ifdef DEBUG
  std::cout << "LINE=" << __LINE__ << std::endl;
  std::cout << "FILE=" << __FILE__ << std::endl;
  std::cout << "DATE=" << __DATE__ << std::endl;
  std::cout << "TIME=" << __TIME__ << std::endl;
#ifndef WIN32
  std::cout << "FUNCTION=" << __PRETTY_FUNCTION__ << std::endl;
#endif

  // この行はプリプロセッサによって以下のように展開される
  // プリプロセスのみさせる場合は -E オプションをつける
  // std::cout << __DATE__ << " " << __TIME__
  //           << " [" << "debug message" << "]"
  //           << " in \"" << __PRETTY_FUNCTION__
  //           << "\" at " << __FILE__
  //           << " line " << __LINE__ << "." << std::endl;
  // あたかも関数のように使えて便利
  MYDEBUG("debug message");
#endif

  return 0;
}
