#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([libperf], [0.1], [jemmons@cs.stanford.edu])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([src/libperf.hh])
AC_CONFIG_HEADERS([src/config.h])

CXX14_FLAGS="-std=c++14"
PICKY_CXXFLAGS="-pedantic -Wall -Wextra -Werror -Wno-non-virtual-dtor"
AC_SUBST([CXX14_FLAGS])
AC_SUBST([PICKY_CXXFLAGS])

# Checks for programs.
AC_PROG_CXX
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h inttypes.h stdint.h stdlib.h string.h unistd.h])

# libperf substitutions
AC_SUBST([LIBPERF_SO_VERSION], [0:0:0])
AC_SUBST([LIBPERF_API_VERSION],[1.0])

# Checks for library functions.
#AC_FUNC_FORK
#AC_FUNC_MALLOC
#AC_CHECK_FUNCS([clock_gettime])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 python/Makefile
])

AC_OUTPUT
