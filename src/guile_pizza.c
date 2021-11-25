/* guile_pizza.c
   Copyright (C) 2021 Ivan Guerreschi

This file is part of pizzac.

Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>

pizzac is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

pizzac is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with pizzac. If not, see <http://www.gnu.org/licenses/>. */

#include <libguile.h>
#include "include/menu.h"

SCM
print_version_wrapper (void)
{    
  return scm_from_locale_string (print_version ());
}

SCM
print_license_wrapper (void)
{    
  return scm_from_locale_string (print_license ());
}

void
init_pizza ()
{
  scm_c_define_gsubr ("print_version", 0, 0, 0, print_version_wrapper);
  scm_c_define_gsubr ("print_license", 0, 0, 0, print_license_wrapper);
}
