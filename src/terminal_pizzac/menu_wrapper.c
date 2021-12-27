/* menu_wrapper.c
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
#include "pizza.h"

void
print_all_pizza (const char *file_name)
{

  FILE *file_pizza, *file_row;
  open_file (&file_pizza, file_name);
  open_file (&file_row, file_name);

  int row = count_row_file (file_row);
  pizza_t *pizza = all_pizzas (file_pizza, row);

  puts ("Flour type-Grams flour-Yeast type-Grams yeast-Grams water-Grams salt-"
        "Grams sugar-Grams oil-Cooking time-Oven temperature");

  for (int i = 0; i < row; i++)
    printf ("%s    %.2lfgr    %s    %.2lfgr    %.2lfgr    %.2lfgr    "
            "%.2lfgr    %.2lfgr    %.2lfgr    %.2lf°\n",
            pizza[i].ingrediants.flour_type, pizza[i].ingrediants.grams_flour,
            pizza[i].ingrediants.yeast_type, pizza[i].ingrediants.grams_yeast,
            pizza[i].ingrediants.grams_water,
            pizza[i].ingrediants.grams_salt,
            pizza[i].ingrediants.grams_sugar,
            pizza[i].ingrediants.grams_oil,
            pizza[i].preparation.cooking_time,
            pizza[i].preparation.oven_temperature);

  for (int i = 0; i < row; i++)
    {
      free (pizza[i].ingrediants.flour_type);
      free (pizza[i].ingrediants.yeast_type);
    }

  free (pizza);
  close_file (&file_pizza);
  close_file (&file_row);
}

void
input_create_pizza (const char *file_name)
{
  pizza_t pizza;
  char buffer[BUFSIZ];

  puts ("Flour type");
  char *flour_type = calloc (50, sizeof (char));

  if (flour_type)
    {

      if (fgets (buffer, sizeof (buffer), stdin))
        {
          buffer[strcspn (buffer, "\r\n")] = 0;
          strcpy (flour_type, buffer);
          pizza.ingrediants.flour_type = calloc (strlen (flour_type) + 1, sizeof (char));

          if (pizza.ingrediants.flour_type)
            {
              strcpy (pizza.ingrediants.flour_type, flour_type);
            }
        }
    }

  free (flour_type);

  puts ("Grams flour");
  double grams_flour;

  if (fgets (buffer, sizeof (buffer), stdin))
    {
      buffer[strcspn (buffer, "\r\n")] = 0;
      grams_flour = atoi (buffer);
      pizza.ingrediants.grams_flour = grams_flour;
    }

  puts ("Yeast type");
  char *yeast_type = calloc (50, sizeof (char));

  if (yeast_type)
    {

      if (fgets (buffer, sizeof (buffer), stdin))
        {
          buffer[strcspn (buffer, "\r\n")] = 0;
          strcpy (yeast_type, buffer);
          pizza.ingrediants.yeast_type = calloc (strlen (yeast_type) + 1, sizeof (char));

          if (pizza.ingrediants.yeast_type)
            {
              strcpy (pizza.ingrediants.yeast_type, yeast_type);
            }
        }
    }

  free (yeast_type);

  puts ("Grams yeast");
  double grams_yeast;

  if (fgets (buffer, sizeof (buffer), stdin))
    {
      buffer[strcspn (buffer, "\r\n")] = 0;
      grams_yeast = atoi (buffer);
      pizza.ingrediants.grams_yeast = grams_yeast;
    }

  puts ("Grams water");
  double grams_water;

  if (fgets (buffer, sizeof (buffer), stdin))
    {
      buffer[strcspn (buffer, "\r\n")] = 0;
      grams_water = atoi (buffer);
      pizza.ingrediants.grams_water = grams_water;
    }

  puts ("Grams salt");
  double grams_salt;

  if (fgets (buffer, sizeof (buffer), stdin))
    {
      buffer[strcspn (buffer, "\r\n")] = 0;
      grams_salt = atoi (buffer);
      pizza.ingrediants.grams_salt = grams_salt;
    }

  puts ("Grams sugar");
  double grams_sugar;

  if (fgets (buffer, sizeof (buffer), stdin))
    {
      buffer[strcspn (buffer, "\r\n")] = 0;
      grams_sugar = atoi (buffer);
      pizza.ingrediants.grams_sugar = grams_sugar;
    }

  puts ("Grams oil");
  double grams_oil;

  if (fgets (buffer, sizeof (buffer), stdin))
    {
      buffer[strcspn (buffer, "\r\n")] = 0;
      grams_oil = atoi (buffer);
      pizza.ingrediants.grams_oil = grams_oil;
    }

  puts ("Cooking time");
  double cooking_time;

  if (fgets (buffer, sizeof (buffer), stdin))
    {
      buffer[strcspn (buffer, "\r\n")] = 0;
      cooking_time  = atoi (buffer);
      pizza.preparation.cooking_time = cooking_time;
    }

  puts ("Oven temperature");
  double oven_temperature;
  if (fgets (buffer, sizeof (buffer), stdin))
    {
      buffer[strcspn (buffer, "\r\n")] = 0;
      oven_temperature = atoi (buffer);
      pizza.preparation.oven_temperature = oven_temperature;
    }

  FILE *file_pizza;
  open_file (&file_pizza, file_name);
  create_pizza (file_pizza, pizza);
  close_file (&file_pizza);

  free (pizza.ingrediants.flour_type);
  free (pizza.ingrediants.yeast_type);
}
