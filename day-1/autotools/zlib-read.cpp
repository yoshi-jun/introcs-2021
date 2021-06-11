#include <iostream>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#if HAVE_ZLIB_H
#include <zlib.h>
#endif

int main(int argc, char *argv[]) {
#if HAVE_ZLIB_H
  gzFile gzif = gzopen("file.gz", "rb6f");
  char buf[0xff];
  gzread(gzif, buf, sizeof(buf));
  std::cout << buf << std::endl;
  return gzclose(gzif);
#endif
}
