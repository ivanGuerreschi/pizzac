# Makefile.am
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

AM_CFLAGS = -I $(top_srcdir)/src/terminal_pizzac/ -I $(top_srcdir)/lib \
	    -Wall -Wextra -Wpedantic \
            -Wformat=2 -Wno-unused-parameter -Wshadow \
            -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
            -Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
	    -Wjump-misses-init -Wlogical-op

nobase_include_HEADERS = include/menu.h include/menu_wrapper.h
bin_PROGRAMS = terminalpizzac
terminalpizzac_SOURCES = terminal_pizzac.c menu.c menu_wrapper.c
terminalpizzac_LDADD = $(top_builddir)/lib/libpizza.a $(AM_LDFLAGS)
