/* terminal_pizzac.c
   Copyright (C) 2021-2022 Ivan Guerreschi

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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/menu.h"
#include "include/menu_wrapper.h"
#include "pizza.h"
#include "info.h"
#include "utility.h"

int
main (void)
{
  puts (print_version ());
  puts (print_license ());

  const char *file = file_name (NAMEFILE);
  int menu = 0;

  while (true)
    {
      menu = print_menu ();

      switch (menu)
        {
        case 1:
          exit (1);
          break;

        case 2:
          print_all_pizza (file);
          break;

        case 3:
          input_create_pizza (file);
          break;
        }
    }

  return 0;
}
