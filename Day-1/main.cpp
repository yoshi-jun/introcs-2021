// std::coutを使うために必要
#include <iostream>

// echo(), add() を使うために必要（プロトタイプ宣言）
// 処理内容は全くわからないけど呼び出しの方法だけは知ることが出来ます
// リンクはできないけどコンパイルだけはできるようになります(-cオプション)
#include "prototypesdef.h"

// 新たにヘッダファイルを用意したくなければ以下のようにしてもよいです
// extern void echo(const char* message);
// extern int add(int x, int y);

int main() {
  std::cout << "calling function echo()" << std::endl;
  echo("This is the function echo().");

  std::cout << "Calling the function add(1, 2): " << add(1, 2) << std::endl;

  return 0;
}
