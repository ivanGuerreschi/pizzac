# configure.ac
# Copyright (C) 2021-2022 Ivan Guerreschi
#
# This file is part of pizzac.
#
# Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
# Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>e
#
# pizzac is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# pizzac is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with pizzac. If not, see <http://www.gnu.org/licenses/>. 

AC_PREREQ([2.69])
AC_INIT([pizzac], [1.0], [ivanguerreschi86@gmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_PROG_CC_C99
AC_PROG_CC
AC_PROG_RANLIB

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([strcspn])

# Check -fanalyze flag
AX_CHECK_COMPILE_FLAG(-fanalyzer, [AX_APPEND_FLAG([-fanalyzer])])

# Check for Guile
PKG_CHECK_MODULES([GUILE], [guile-3.0])

# Check for GTK4
PKG_CHECK_MODULES([GTK], [
    glib-2.0
    gtk4
])

AC_CONFIG_FILES([Makefile
		 lib/Makefile
 		 src/terminal_pizzac/Makefile
		 src/guile_pizzac/Makefile
		 src/gtk_pizzac/Makefile])
AC_OUTPUT
