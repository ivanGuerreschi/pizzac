/* main.c
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
#include "include/menu.h"
#include "pizza.h"
#include "info.h"

int
main (void)
{
  puts (print_version ());
  puts (print_license ());

  FILE *file_pizza, *file_row;
  char *file;
  const char *file_name = "/home/ivan/.pizza.txt";

  file = malloc (strlen (getenv ("HOME")) + strlen (file_name) + 1);
  strcat (strcpy (file, getenv ("HOME")), file_name);

  free (file);

  open_file (&file_pizza, file_name);
  open_file (&file_row, file_name);

  int row = count_row_file (file_row);
  pizza_t *pizza = all_pizzas (file_pizza, row);

  int menu = 0;

  while (true)
    {
      menu = print_menu ();

      switch (menu)
        {
        case 1:
          for (int i = 0; i < row; i++)
            {
              free (pizza[i].ingrediants.flour_type);
              free (pizza[i].ingrediants.yeast_type);
            }

          free (pizza);
          close_file (&file_pizza);
		  close_file (&file_row);

          exit (1);
          break;

        case 2:
          for (int i = 0; i < row; i++)
            printf ("%s-%.2lf-%s-%.2lf-%.2lf-%.2lf-%.2lf-%.2lf-%.2lf-%.2lf\n",
                    pizza[i].ingrediants.flour_type, pizza[i].ingrediants.grams_flour,
                    pizza[i].ingrediants.yeast_type, pizza[i].ingrediants.grams_yeast,
                    pizza[i].ingrediants.grams_water,
                    pizza[i].ingrediants.grams_salt,
                    pizza[i].ingrediants.grams_sugar,
                    pizza[i].ingrediants.grams_oil,
                    pizza[i].preparation.cooking_time,
                    pizza[i].preparation.oven_temperature);
        }
    }

  return 0;
}
