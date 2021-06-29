#include <iostream>
#include <zlib.h>

int main(int argc, char* argv[]) {
  gzFile gzof = gzopen("file.gz", "wb6f");
  std::string str = "using zlib functions...";
  std::cout << str << std::endl;
  gzwrite(gzof, str.c_str(), str.length());
  return gzclose(gzof);
}
