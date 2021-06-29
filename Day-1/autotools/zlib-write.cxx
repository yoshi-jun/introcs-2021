#include <iostream>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#if HAVE_ZLIB_H
#include <zlib.h>
#endif

int main(int argc, char *argv[])
{
#if HAVE_ZLIB_H
  gzFile gzof = gzopen("file.gz", "wb6f");
  std::string str = "using zlib functions...";
  std::cout << str << std::endl;
  gzwrite(gzof, str.c_str(), str.length());
  return gzclose(gzof);
#endif
}
