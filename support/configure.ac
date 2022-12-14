dnl Template file for GNU Autoconf
dnl Copyright (C) 1996  Mario Mikocevic Mozgy

dnl This program is free software; you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation; either version 2 of the License, or
dnl (at your option) any later version.

dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.

dnl You should have received a copy of the GNU General Public License
dnl along with this program; if not, write to the Free Software
dnl Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


dnl
dnl Process this file with autoconf to produce a configure script.
dnl

AC_INIT
AC_CONFIG_SRCDIR([../sasm/sasm.c])
AC_CONFIG_HEADERS([config.h])

dnl
dnl Version of a HP Tools ...
dnl
VERSION=`sed -e 's/^.*Tools \(.*\)"$/\1/' ../include/version.h`
echo "Configuring for HPTools $VERSION"
AC_SUBST(VERSION)

dnl
dnl Get cannonical host
dnl
AC_CANONICAL_HOST
AC_DEFINE_UNQUOTED(OS_TYPE, "$host_os")

dnl
dnl Find a good install
dnl
AC_PROG_INSTALL

dnl
dnl Find the compiler
dnl

dnl We want these before the checks, so the checks can modify their values.
test -z "$CFLAGS"  && CFLAGS= auto_cflags=1
test -z "$CC" && cc_specified=yes

AC_PROG_CC
AC_PROG_CPP

dnl
dnl if the user hasn't specified CFLAGS, then
dnl   if compiler is gcc, then use -O2 and some warning flags
dnl   else use os-specific flags or -O
dnl
if test -n "$auto_cflags"; then
  if test -n "$GCC"; then
    CFLAGS="$CFLAGS -O2 -Wall -Wno-switch -Wno-uninitialized -Wno-implicit"
  else
    case "$host_os" in
      *hpux*) CFLAGS="$CFLAGS +O3 -Aa -D_HPUX_SOURCE" ;;
      *) CFLAGS="$CFLAGS -O" ;;
    esac
  fi
fi

dnl
dnl Handle AIX
dnl
AC_USE_SYSTEM_EXTENSIONS

dnl
dnl Checks for header files.
dnl
AC_CHECK_HEADERS(unistd.h string.h sys/time.h errno.h dos.h)

dnl
dnl Checks for typedefs, structures, and compiler characteristics.
dnl
AC_C_CONST
AC_TYPE_SIZE_T
AC_STRUCT_TM

dnl
dnl Return type of signal-handlers
dnl

dnl
dnl Checks for library functions.
dnl
AC_FUNC_VPRINTF
AC_CHECK_FUNCS(getopt strcspn)
dnl Add check for str* series (strchr)
dnl AC_CHECK_FUNCS(strdup select strerror symlink)

dnl
dnl Checks for libraries.
dnl
dnl AC_CHECK_LIB(socket, main)

dnl if test "${with_socks}" = "yes"
dnl then
dnl   AC_CHECK_LIB(socks, Rconnect)
dnl fi

dnl
dnl Check for sys_errlist declaration
dnl
AC_MSG_CHECKING(for sys_errlist declaration)
AC_RUN_IFELSE([AC_LANG_SOURCE([[
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
main() { char *s = sys_errlist[0]; exit(0); }
]])],[AC_DEFINE(SYS_ERRLIST_DECLARED) AC_MSG_RESULT(yes)],[AC_MSG_RESULT(no)],[:])

dnl
dnl Create output
dnl
AC_CONFIG_FILES([Makefile version.c.SH])
AC_OUTPUT
