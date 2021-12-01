/* pizza.c
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

#include <stdlib.h>
#include <stdio.h>
#include "pizza.h"

void
open_file (FILE **file, const char *file_name)
{
  if ((*file = fopen (file_name, "a+")) == NULL)
    {
      perror ("Error open file");
      exit (1);
    }
}

void
close_file (FILE **file)
{
  if (fclose (*file) != 0)
    perror ("Error close file");
}

int
count_row_file (FILE *file)
{
  char c;
  int count = 0;
  for (c = getc (file); c != EOF; c = getc (file))
    if (c == '\n')
      count++;

  return count;
}

pizza_t
*all_pizzas (FILE *file, int row)
{
  pizza_t *pizza = calloc (row + 1, sizeof (pizza_t));

  if (pizza == NULL)
    {
      perror ("Error allocation failed");
      exit (0);
    }

  for (int i = 0; i < row; i++)
    {
      pizza[i].ingrediants.flour_type = malloc (50 * sizeof (char));
      pizza[i].ingrediants.yeast_type = malloc (50 * sizeof (char));
    }

  int n = 0;
  int res = 0;

  while (1)
    {
      res = fscanf (file, "%s", pizza[n].ingrediants.flour_type);
      if (res != 1)
	break;

      res = fscanf (file, "%lf", &pizza[n].ingrediants.grams_flour);
      if (res != 1)
	break;

      res = fscanf (file, "%s", pizza[n].ingrediants.yeast_type);
      if (res != 1)
	break;

      res = fscanf (file, "%lf", &pizza[n].ingrediants.grams_yeast);
      if (res != 1)
	break;

      res = fscanf (file, "%lf", &pizza[n].ingrediants.grams_water);
      if (res != 1)
	break;

      res = fscanf (file, "%lf", &pizza[n].ingrediants.grams_salt);
      if (res != 1)
	break;

      res = fscanf (file, "%lf", &pizza[n].ingrediants.grams_sugar);
      if (res != 1)
	break;

      res = fscanf (file, "%lf", &pizza[n].ingrediants.grams_oil);
      if (res != 1)
	break;


      res = fscanf (file, "%lf", &pizza[n].preparation.cooking_time);
      if (res != 1)
	break;

      res = fscanf (file, "%lf", &pizza[n].preparation.oven_temperature);
      if (res != 1)
        {
          perror ("Error read file");
          exit (1);
        }
      n++;
    } 
 
  return pizza;
}
