// std::coutを使うために必要
#include <iostream>

// 実行可能ファイルの元になる main 関数
// main 関数は整数（int）を返す
// main 関数は void という引数をとる（＝引数をとらない）
int main() {
  // std::cout に << でつなげて出力内容を渡していきます
  std::cout << "Hello, World!" << std::endl;

  // UNIX では 0 は正常終了を意味します
  return 0;
}
