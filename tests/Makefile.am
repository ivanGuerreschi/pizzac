# Makefile.am
# Copyright (C) 2021-2022 Ivan Guerreschi

# Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
# Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>e

# This file is part of pizzac.

# pizzac is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# pizzac is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with pizzac. If not, see <http://www.gnu.org/licenses/>.

TESTS = file_pizzac_test file_pizzac_xfail_test all_pizzas_test new_pizza_test
XFAIL_TESTS = file_pizzac_xfail_test
check_PROGRAMS = $(TESTS)

file_pizzac_test_SOURCES = file_pizzac_test.c 
file_pizzac_test_CFLAGS = -I $(top_srcdir)/lib
file_pizzac_test_LDADD = $(top_builddir)/lib/libpizza.a

all_pizzas_test_SOURCES = all_pizzas_test.c
all_pizzas_test_CFLAGS = -I $(top_srcdir)/lib
all_pizzas_test_LDADD = $(top_builddir)/lib/libpizza.a

new_pizza_test_SOURCES = new_pizza_test.c 
new_pizza_test_CFLAGS = -I $(top_srcdir)/lib
new_pizza_test_LDADD = $(top_builddir)/lib/libpizza.a

file_pizzac_xfail_test_SOURCES = file_pizzac_xfail_test.c 
file_pizzac_xfail_test_CFLAGS = -I $(top_srcdir)/lib
file_pizzac_xfail_test_LDADD = $(top_builddir)/lib/libpizza.a
