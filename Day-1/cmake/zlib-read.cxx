#include <iostream>
#include <zlib.h>

int main(int argc, char* argv[]) {
  gzFile gzif = gzopen("file.gz", "rb6f");
  char buf[0xff];
  gzread(gzif, buf, sizeof(buf));
  std::cout << buf << std::endl;
  return gzclose(gzif);
}
