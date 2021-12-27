/* terminal_pizzac.c
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "include/menu.h"
#include "include/menu_wrapper.h"
#include "pizza.h"
#include "info.h"

int
main (void)
{
  puts (print_version ());
  puts (print_license ());

  char *file_name;
  const char *file_pizza = "/.pizza.txt";

  if ((file_name = getenv ("HOME")) == NULL)
    file_name = getpwuid (getuid())->pw_dir;

  strcat (file_name, file_pizza);

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
          print_all_pizza (file_name);
          break;

        case 3:
          input_create_pizza (file_name);
          break;
        }
    }

  return 0;
}
