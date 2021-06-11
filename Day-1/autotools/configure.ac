#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.60])
AC_INIT(
  [zlib-read-write],
  [1.2.3],
  [go.iwai@kek.jp]
)
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([zlib-read.cpp])
AC_CONFIG_SRCDIR([zlib-write.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AC_CHECK_HEADERS(
  [zlib.h],
  [AC_DEFINE(HAVE_ZLIB_H)],
  [AC_MSG_ERROR([No zlib.h found in the system.])]
)
# Checks for header files.
AC_CHECK_LIB(
  z,
  gzopen,
  [FOUND_ZLIB="yes"],
  [AC_MSG_ERROR([No zlib library found in the system.])]
)
AS_IF(
  [test "x$FOUND_ZLIB" = xyes],
  [AC_LIB_LINKFLAGS([z])]
)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
