/* info.c
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "info.h"

const char
*print_license (void)
{
  return "This program is free software: you can redistribute it and/or modify\n"
         "it under the terms of the GNU General Public License as published by\n"
         "the Free Software Foundation, either version 3 of the License, or\n"
         "(at your option) any later version.\n\n"

         "This program is distributed in the hope that it will be useful,\n"
         "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
         "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
         "GNU General Public License for more details.\n\n"

         "You should have received a copy of the GNU General Public License\n"
         "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n";
}

const char
*print_version (void)
{
  return PACKAGE_STRING;
}
