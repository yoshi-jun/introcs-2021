# Usage

```shell
% ls
Makefile.am  configure.ac  zlib-read.cpp  zlib-write.cpp

# reads configure.ac, then creates aclocal.m4
% aclocal
# reads configure.ac, then creates config.h.in
% autoheader
# reads configure.ac and aclocal.m4, then creates configure
% autoconf
# reads configure.ac, config.h.in, and makefile.am, then creates makefile.in.
% automake --add-missing --copy

# creates config.h and Makefile
% ./configure
# builds zlib-read.exe and zlib-write.exe
% make
```
