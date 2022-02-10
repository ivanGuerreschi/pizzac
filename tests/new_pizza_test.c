/* new_pizza_test.c
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

#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "pizza.h"
#include "include/utility_test.h"

int
main (void)
{
  int value = 0;

  const char *file = file_name (NAMEFILETEST);

  FILE *file_pizza, *file_row;
  open_file (&file_pizza, file);
  open_file (&file_row, file);

  int row = count_row_file (file_row);

  pizza_t new_pizza;

  new_pizza.ingrediants.flour_type = (char *) malloc (50 * sizeof (char));
  if (new_pizza.ingrediants.flour_type)
    strcpy (new_pizza.ingrediants.flour_type, "00");

  new_pizza.ingrediants.grams_flour = 500;

  new_pizza.ingrediants.yeast_type = (char *) malloc (50 * sizeof (char));
  if (new_pizza.ingrediants.yeast_type)
    strcpy (new_pizza.ingrediants.yeast_type, "secco");

  new_pizza.ingrediants.grams_yeast = 7;

  new_pizza.ingrediants.grams_water = 300;
  new_pizza.ingrediants.grams_oil = 15;
  new_pizza.ingrediants.grams_salt = 9;
  new_pizza.ingrediants.grams_sugar = 10;

  new_pizza.preparation.cooking_time = 20;
  new_pizza.preparation.oven_temperature = 270;

  new_pizza.preparation.condiment = (char *) malloc (50 * sizeof (char));
  if (new_pizza.preparation.condiment)
    strcpy (new_pizza.preparation.condiment, "salame");

  create_pizza (file_pizza, new_pizza);

  free (new_pizza.ingrediants.flour_type);
  new_pizza.ingrediants.flour_type = NULL;
  free (new_pizza.ingrediants.yeast_type);
  new_pizza.ingrediants.yeast_type = NULL;
  free (new_pizza.preparation.condiment);
  new_pizza.preparation.condiment = NULL;

  pizza_t *pizza = all_pizzas (file_pizza, row);

  if ((pizza[row].ingrediants.grams_flour = 1500) &&
      (pizza[row].preparation.cooking_time = 20))
    value = 0;
  else
    value = 1;

  close_file (&file_pizza);
  close_file (&file_row);

  for (int i = 0; i < row; i++)
    {
      free (pizza[i].ingrediants.flour_type);
      free (pizza[i].ingrediants.yeast_type);
      free (pizza[i].preparation.condiment);
    }

  free (pizza);
  pizza = NULL;

  return value;
}
