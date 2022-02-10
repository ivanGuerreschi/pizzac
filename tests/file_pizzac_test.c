/* file_pizzac_test.c
   Copyright (C) 2021-2022 Ivan Guerreschi

Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>

This file is part of pizzac.

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

#include <string.h>
#include "utility.h"
#include "include/utility_test.h"

int
main (void)
{
  const char *file = file_name (NAMEFILETEST);

  if (strcmp (file, "/home/ivan/.pizzatest.txt") == 0)
    {
      return 0;
    }
  else
    {
      return 1;
    }
}
